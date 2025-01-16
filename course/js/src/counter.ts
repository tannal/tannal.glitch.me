import * as ffi from 'node-ffi-napi';
import * as path from 'path';
import { CounterLib, HWND } from './types';

class ModernCounter {
  private counterLib: CounterLib;

  constructor() {
    const dllPath = path.resolve(__dirname, '../counter.dll');
    console.log(`Loading DLL from: ${dllPath}`);

    this.counterLib = ffi.Library(dllPath, {
      'initialize': ['void', []],
      'create_window': [HWND, []],
      'process_messages': ['bool', []]
    }) as CounterLib;
  }

  async run(): Promise<number> {
    try {
      console.log('Initializing window class...');
      this.counterLib.initialize();

      console.log('Creating window...');
      const hwnd = this.counterLib.create_window();
      if (!hwnd) {
        throw new Error('Failed to create window');
      }
      console.log('Window created successfully');

      console.log('Starting message loop...');
      const result = this.counterLib.process_messages();
      if (!result) {
        throw new Error('Message loop failed');
      }

      return 0;
    } catch (error) {
      console.error('Error:', error);
      return 1;
    }
  }
}

async function main() {
  try {
    console.log('Starting ModernCounter application...');
    const app = new ModernCounter();
    const exitCode = await app.run();
    process.exit(exitCode);
  } catch (error) {
    console.error('Fatal error:', error);
    process.exit(1);
  }
}

main().catch(console.error);
