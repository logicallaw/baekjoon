#!/usr/bin/env python3
import os
import sys
import pty
import select
import subprocess
import termios
import tty

# === 설정: 출력 색상 (Cyan 권장) ===
# 입력은 터미널 기본색(흰색/회색), 출력은 눈에 띄는 색으로 분리
COLOR_OUTPUT = "\033[1;36m" # Bold Cyan
COLOR_RESET = "\033[0m"

def run(executable_path):
    # 1. PTY(가상 터미널) 마스터/슬레이브 생성
    master_fd, slave_fd = pty.openpty()

    # 2. 슬레이브 터미널의 ECHO(입력 문자 다시 보여주기) 끄기
    #    이유: 우리가 입력한 글자가 프로그램 출력 흐름에 섞여서 색칠되는 것을 방지
    #    입력은 사용자의 실제 터미널에서만 보이고, 프로그램 내부로 조용히 전달됨
    attrs = termios.tcgetattr(slave_fd)
    attrs[3] = attrs[3] & ~termios.ECHO
    termios.tcsetattr(slave_fd, termios.TCSANOW, attrs)

    # 3. C++ 프로세스 실행 (stdout/stderr를 슬레이브 PTY로 연결)
    #    PTY를 쓰므로 C++은 line-buffering 모드로 동작하여 즉각 반응함
    process = subprocess.Popen(
        [executable_path],
        stdin=slave_fd,
        stdout=slave_fd,
        stderr=slave_fd,
        preexec_fn=os.setsid, # 프로세스 그룹 분리
        close_fds=True
    )
    os.close(slave_fd) # 부모 프로세스에서는 슬레이브 핸들 불필요

    try:
        # 4. 입출력 루프 (I/O Multiplexing)
        while process.poll() is None:
            # 사용자의 키보드 입력(stdin)과 프로그램의 출력(master_fd)을 동시에 감시
            r, w, e = select.select([sys.stdin, master_fd], [], [], 0.1)

            # [상황 A] 프로그램이 뭔가를 출력함
            if master_fd in r:
                try:
                    data = os.read(master_fd, 1024)
                    if not data: break
                    # 출력 데이터에만 색상을 입혀서 화면에 표시
                    sys.stdout.buffer.write(
                        ID_COLOR_OUTPUT.encode() + data + COLOR_RESET.encode()
                    )
                    sys.stdout.flush()
                except OSError:
                    break

            # [상황 B] 사용자가 키보드로 입력함
            if sys.stdin in r:
                user_input = os.read(sys.stdin.fileno(), 1024)
                if not user_input: break # EOF
                # 사용자의 입력을 프로그램(PTY)에 전달
                os.write(master_fd, user_input)

    except KeyboardInterrupt:
        pass # Ctrl+C 처리 위임
    finally:
        # 종료 처리
        sys.stdout.write(COLOR_RESET)
        if process.poll() is None:
            process.terminate()
        os.close(master_fd)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <executable>")
        sys.exit(1)
    
    # 전역 색상 변수 적용을 위해 재정의
    ID_COLOR_OUTPUT = COLOR_OUTPUT 
    run(sys.argv[1])

