import * as ref from 'ref-napi';

export const HWND = ref.types.void;
export type HWND = Buffer;

export interface CounterLib {
  initialize: () => void;
  create_window: () => HWND;
  process_messages: () => boolean;
}
