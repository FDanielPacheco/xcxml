#include <xcxml.h>

#include <stdint.h>
#include <stdio.h>
#include <errno.h>

int
main( void ){
  const char * path = "dataset.xml";
  const char * params[ ] = {
    "/root_tag/first_lvl/second_lvl/value",
    "/root_tag/outside_value",
    "/root_tag/non_existing_tag"
  };

  char buf[ 255 ];

  for( int i = 0 ; i < 3 ; ++i ){
    int8_t code = xml_get_value( 
      path,
      params[ i ],
      buf,
      sizeof(buf)
    );
    
    if( -1 == code && !errno ){
      printf("The %s was not found...\n", params[ i ]);
      continue;
    }
   
    printf("The %s was found with value %s...\n", params[ i ], buf );
  }

  return 0;
}
