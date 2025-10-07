# xcxml
`xcxml` is a C wrapper library designed to simplify reading XML files based on the `libxml2` library. 
With a single call, you can open and close an XML file and retrieve a value from a specified XML path.

---

## Installation

### Dependencies

In Debian-based Linux:
```bash
sudo apt install libxml2
```

### Prebuilt binaries

Available platforms:
- `x86_64-linux-gnu` (Intel/AMD)
- `arm-linux-gnueabihf` (e.g. Raspberry Pi 32-bit CPU)
- `aarch64-linux-gnu` (e.g. Raspberry Pi 64-bit CPU)

```bash
# Download and extract pre-compiled library
wget https://github.com/FDanielPacheco/xcxml/releases/download/alpha/libxcxml-<platform>.zip
unzip libxcxml-<platform>.zip

# Install using the provided script
chmod u+x install.sh
./install.sh 
```

### Build from source

Build Requirements:
- clang: Compiler frontend and Linker
- opt: Optimizer
- llc: Compiler backend
- llvm-ar: Build static library 
- C Standard Library (lc)
- XML toolkit ([libxml2](https://github.com/GNOME/libxml2))

```bash
sudo apt install build-essential llvm clang libxml2-dev
```

Clone the repository:
```bash
git clone https://github.com/FDanielPacheco/xcxml.git
cd xcxml
```

Build the dynamic library for the host platform:
```bash
make
```

Build the dynamic library for all platforms listed above:
```bash
make all
```

Build for a specific target and type independent on the host platform (require the dynamic/static libraries for that platform):
```bash
make release TARGET_ARCH_LLC=<arch> TARGET_ARCH_CC=<triplet> TYPE=<so|a> CF=-fPIC LF="-relocation-model=pic"
```

`<arch,triplet>` examples:
- `arm`, `arm-linux-gnueabihf`
- `x86-64`, `x86_64-linux-gnu`
- `aarch64`, `aarch64-linux-gnu`
 
`<TYPE>`: Dynamic: so | Static: a

---
## Usage Example 

```c
#include <xcxml.h>
#include <stdio.h>
#include <errno.h>

int
main( void ){
  const char * path = "dataset.xml";
  const char * field = "/root_tag/first_lvl/second_lvl/value";
  
  char buf[ 255 ];

  int8_t code = xml_get_value( 
    path,
    field,
    buf,
    sizeof(buf)
  );
    
  if( -1 == code && !errno )
    printf("The %s was not found...\n", params[ i ]);
  printf("The %s was found with value %s...\n", params[ i ], buf );

  return 0;
}
```

### Included example

```bash
make example

cd test
./../build/read_example
```


## Documentation

API documentation generation (from xcxml directory):
```bash
make documentation
```
Manual pages: `man docs/man/man3/xcxml.c.3` or `man docs/man/man3/xcxml.h.3` \
HTML docs: `firefox docs/html/index.html`

Additional:
- [GNOME Project libxml2](https://gnome.pages.gitlab.gnome.org/libxml2/html/)

---
## Author

Fábio D. Pacheco \
Email: fabio.d.pacheco@inesctec.pt

## License

[MIT License](https://opensource.org/license/mit) 
