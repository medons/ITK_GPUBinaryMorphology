if (ITK_USE_GPU)
  set(ITKGPUBinaryMorphology_SRC
    )

  set(ITKGPUBinaryMorphology_Kernels
    GPUBinaryErodeImageFilter.cl
    GPUBinaryDilateImageFilter.cl
    )

  write_gpu_kernels("${ITKGPUBinaryMorphology_Kernels}" ITKGPUBinaryMorphology_SRC)

  add_library(ITKGPUBinaryMorphology ${ITKGPUBinaryMorphology_SRC})
  target_link_libraries(ITKGPUBinaryMorphology ${GPUCommon_LIBRARIES} ${ITKCommon_LIBRARIES} ${OPENCL_LIBRARIES} )
  itk_module_target(ITKGPUBinaryMorphology)
else(ITK_USE_GPU)
  message(FATAL_ERROR "ERROR: ITK_USE_GPU must be enabled to build ITKGPUBinaryMorphology")
endif(ITK_USE_GPU)
