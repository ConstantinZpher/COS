# C.O.S
## Build Process
- `docker run --rm -it -v "%cd%":/root/env cos-buildenv`

- `make build-x86_64`

- `qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso`

-----------------------------------------