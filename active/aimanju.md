


```
#!/usr/bin/env python3
"""
Scriptum ad emendandas notas typorum in repositorio bifurcato (fork) 'comfy_kitchen'.
Permittit usum cum vetustioribus versionibus PyTorch (< 2.7.0).
"""

import os
import re
import sys

TARGET_DIR = "/root/ENTER/envs/comfyui/lib/python3.10/site-packages/comfy_kitchen"


def patch_content(text: str) -> tuple[str, bool]:
    original_text = text

    # Regulae substitutionis pro typis
    substitutions = [
        (r"\blist\[int\]", "typing.List[int]"),
        (r"\blist\[bool\]", "typing.List[bool]"),
        (r"\blist\[float\]", "typing.List[float]"),
        (r"\blist\[str\]", "typing.List[str]"),
        (r"\btorch\.Tensor \| None\b", "typing.Optional[torch.Tensor]"),
        (r"\bTensor \| None\b", "typing.Optional[Tensor]"),
        (r"\bfloat \| None\b", "typing.Optional[float]"),
        (r"\bint \| None\b", "typing.Optional[int]"),
        (r"\bbool \| None\b", "typing.Optional[bool]"),
        (r"\bstr \| None\b", "typing.Optional[str]"),
    ]

    for pattern, replacement in substitutions:
        text = re.sub(pattern, replacement, text)

    # Structura capitis fasciculi
    lines = text.splitlines(keepends=True)
    has_future = any("from __future__ import annotations" in line for line in lines)

    # Lineas veteres tollit ne multiplicentur
    cleaned_lines = [
        line
        for line in lines
        if "from __future__ import annotations" not in line
        and line.strip() != "import typing"
    ]

    header_lines = []
    if has_future:
        header_lines.append("from __future__ import annotations\n")
    header_lines.append("import typing\n")

    new_text = "".join(header_lines) + "".join(cleaned_lines)
    changed = (new_text != original_text)
    return new_text, changed


def run_patcher(directory: str) -> None:
    if not os.path.isdir(directory):
        print(f"Error: Directarium non inventum est -> {directory}")
        sys.exit(1)

    patched_count = 0
    scanned_count = 0

    print(f"Lustratio incipit in: {directory}")

    for root, _, files in os.walk(directory):
        for fname in files:
            if not fname.endswith(".py"):
                continue

            scanned_count += 1
            fpath = os.path.join(root, fname)

            with open(fpath, "r", encoding="utf-8") as fp:
                content = fp.read()

            new_content, modified = patch_content(content)

            if modified:
                with open(fpath, "w", encoding="utf-8") as fp:
                    fp.write(new_content)
                patched_count += 1
                rel_path = os.path.relpath(fpath, directory)
                print(f"  [EMENDATUM] {rel_path}")

    print("-" * 50)
    print(f"Fasciculi perlustrati: {scanned_count}")
    print(f"Fasciculi refecti:     {patched_count}")
    print("Operatio feliciter peracta est.")


if __name__ == "__main__":
    target = sys.argv[1] if len(sys.argv) > 1 else TARGET_DIR
    run_patcher(target)
```
