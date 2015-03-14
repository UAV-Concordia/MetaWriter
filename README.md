MetaWriter
==========
Exif writer for embedding metadata

### Install
The Windows installation is quite a pain. It works, but this tool is a porting from linux then it run on Cygwin. The ExifTool API do not implements any functionality by itself, instead it calls the system ExifTool. Therefore it is mandatory to install the original ExitTool application and have it on the system path.

### Metadata required
The metadata required for importing any picture in Pix4D are:
 * GPSAltitude
 * GPSLatitude
 * GPSLongitude
 * FocalLength
 * PixelSize _attribute not found_
If some of these tag are not embedded Pix4D will use a default value.

### Design
This repository include the [ExifTool API](http://owl.phy.queensu.ca/~phil/cpp_exiftool/). The MetaWriter class act as a facade to the ExifTool to embed the metadata used by Pix4d. All attribute will be committed after calling `saveMeta()`.
