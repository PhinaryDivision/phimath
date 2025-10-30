add_executable(test-vec3)
target_sources(test-vec3 PRIVATE test-vec3.cpp)
target_compile_features(test-vec3 PRIVATE cxx_std_20)
target_link_libraries(test-vec3 PRIVATE phimath)
