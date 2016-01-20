set(cJSON_SRCS cJSON.c)

add_library(libcjson ${cJSON_SRCS})	

set(LIBRARY_OUTPUT_PATH ${SCALLOP_SOURCE_DIR}/lib)	
set_target_properties(libcjson PROPERTIES OUTPUT_NAME "cjson")

