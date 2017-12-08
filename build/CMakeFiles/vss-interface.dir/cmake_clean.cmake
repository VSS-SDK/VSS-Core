file(REMOVE_RECURSE
  "libvss-interface.pdb"
  "libvss-interface.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/vss-interface.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
