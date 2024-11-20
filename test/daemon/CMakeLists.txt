add_executable(phihash phihash.cpp)

target_link_libraries(phihash PRIVATE ethash -levent)
target_include_directories(phihash PRIVATE ${ETHASH_PRIVATE_INCLUDE_DIR})
set_target_properties(phihash PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)