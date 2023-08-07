# C.O.S
## Build Process
- `docker run --rm -it -v "%cd%":/root/env cos-buildenv`

- `make build-x86_64`

- `qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso`

-----------------------------------------
Make sure to install the following dependencies or use the existing docker container:
- nasm
- xorriso
- grub-pc-bin
- grub-common
- build-essential
