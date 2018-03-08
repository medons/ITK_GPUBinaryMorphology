set(DOCUMENTATION "This module contains classes for GPU (OpenCL) accelerated binary morphology.")

itk_module(ITKGPUBinaryMorphology
	DEPENDS
		ITKGPUCommon
		ITKBinaryMathematicalMorphology
	TEST_DEPENDS
		ITKTestKernel
	DESCRIPTION
	"${DOCUMENTATION}"
)
