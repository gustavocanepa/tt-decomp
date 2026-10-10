# Original files

Nothing from the game is ever committed. Dump your own disc and put the image here:

```
orig/SCUS-97502/Tourist Trophy (USA).iso
```

Then extract the executable and convert it (decryption, decompression, ELF):

```sh
python tools/iso_extract.py "orig/SCUS-97502/Tourist Trophy (USA).iso" CORE.TT SYSTEM.CNF SCUS_975.02 -o orig/SCUS-97502/files
python tools/core2elf.py orig/SCUS-97502/files/CORE.TT orig/SCUS-97502/CORE.TT.elf
```

`CORE.TT` is encrypted with Salsa20 (unlike retail GT4's `CORE.GT4`) and then raw-deflate
compressed; `core2elf.py` handles both layers (format: the Gran Turismo Modding Hub's
"CORE - PS2 Executables" page).

## Expected hashes (SCUS-97502, version 1.00)

| File | SHA-1 |
|---|---|
| `SYSTEM.CNF` | `ccd5efbd54864101012887db1f545b2a64f008ff` |
| `SCUS_975.02` (bootstrap) | `dc5f096240a84857cff840dfa116c50f8fca165e` |
| `CORE.TT` (as on disc) | `9cb7853cdc54ea72ad529976102d2bdaa1d3c4b6` |
| `CORE.TT.elf` (from `core2elf.py`) | `2466a9ffcde6743649da987ae119287077d61112` |
