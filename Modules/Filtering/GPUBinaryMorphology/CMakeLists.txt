project(ITKGPUBinaryMorphology)

if (ITK_USE_GPU)
  set(ITKGPUBinaryMorphology_LIBRARIES ITKGPUBinaryMorphology)
  set(ITKGPUBinaryMorphology_SYSTEM_INCLUDE_DIRS ${OPENCL_INCLUDE_DIRS})
  set(ITKGPUBinaryMorphology_SYSTEM_LIBRARY_DIRS ${OPENCL_LIBRARIES})
endif()

itk_module_impl()
