from ctypes import CDLL, WINFUNCTYPE, c_int, c_void_p, windll
from pathlib import Path
import sys

class ModernCounter:
    def __init__(self):
        try:
            # 获取当前脚本所在目录
            dll_path = Path(__file__).parent / "counter.dll"
            print(f"Looking for DLL at: {dll_path}")

            if not dll_path.exists():
                raise FileNotFoundError(f"DLL not found at {dll_path}")

            # 加载 DLL
            self.counter_lib = CDLL(str(dll_path))
            print("DLL loaded successfully")

            # 设置函数签名
            self.counter_lib.initialize.restype = None
            self.counter_lib.create_window.restype = c_void_p
            self.counter_lib.process_messages.restype = None
            print("Function signatures set")

        except Exception as e:
            print(f"Initialization error: {e}", file=sys.stderr)
            raise

    def run(self):
        try:
            print("Initializing window class...")
            self.counter_lib.initialize()

            print("Creating window...")
            hwnd = self.counter_lib.create_window()
            if not hwnd:
                raise RuntimeError("Failed to create window")
            print(f"Window created with handle: {hwnd}")

            print("Starting message loop...")
            self.counter_lib.process_messages()

        except Exception as e:
            print(f"Runtime error: {e}", file=sys.stderr)
            return 1

        return 0

def main():
    try:
        print("Starting ModernCounter application...")
        app = ModernCounter()
        return app.run()
    except Exception as e:
        print(f"Fatal error: {e}", file=sys.stderr)
        return 1

if __name__ == "__main__":
    sys.exit(main())
