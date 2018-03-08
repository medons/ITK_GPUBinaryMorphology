itk_module_test()
set(ITKGPUBinaryMorphologyTests
itkGPUBinaryDilateImageFilterTest3.cxx
itkGPUBinaryErodeImageFilterTest3.cxx
)

set(ITKGPUBinaryMorphology-Test_LIBRARIES
  ITKGPUCommon
  ITKGPUBinaryMorphology
)

CreateTestDriver(ITKGPUBinaryMorphology  "${ITKGPUBinaryMorphology-Test_LIBRARIES}" "${ITKGPUBinaryMorphologyTests}")

itk_add_test(NAME itkGPUBinaryDilateImageFilterTest-100-0-0
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare-MD5 ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-100-0-0.png
    "6fd97580a84c71b381d220b132b1335a"
    itkGPUBinaryDilateImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-100-0-0.png 100 0 0 10)
itk_add_test(NAME itkGPUBinaryDilateImageFilterTest-100-0-1
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryDilateImageFilterTest-100-0-1.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-100-0-1.png
    itkGPUBinaryDilateImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-100-0-1.png 100 0 1 10)
itk_add_test(NAME itkGPUBinaryDilateImageFilterTest-100-150-0
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryDilateImageFilterTest-100-150-0.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-100-150-0.png
    itkGPUBinaryDilateImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-100-150-0.png 100 150 0 10)
itk_add_test(NAME itkGPUBinaryDilateImageFilterTest-100-150-1
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryDilateImageFilterTest-100-150-1.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-100-150-1.png
    itkGPUBinaryDilateImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-100-150-1.png 100 150 1 10)
itk_add_test(NAME itkGPUBinaryDilateImageFilterTest-200-0-0
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryDilateImageFilterTest-200-0-0.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-200-0-0.png
    itkGPUBinaryDilateImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-200-0-0.png 200 0 0 10)
itk_add_test(NAME itkGPUBinaryDilateImageFilterTest-200-0-1
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryDilateImageFilterTest-200-0-1.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-200-0-1.png
    itkGPUBinaryDilateImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-200-0-1.png 200 0 1 10)
itk_add_test(NAME itkGPUBinaryDilateImageFilterTest-200-150-0
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryDilateImageFilterTest-200-150-0.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-200-150-0.png
    itkGPUBinaryDilateImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-200-150-0.png 200 150 0 10)
itk_add_test(NAME itkGPUBinaryDilateImageFilterTest-200-150-1
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryDilateImageFilterTest-200-150-1.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-200-150-1.png
    itkGPUBinaryDilateImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryDilateImageFilterTest-200-150-1.png 200 150 1 10)
itk_add_test(NAME itkGPUBinaryErodeImageFilterTest-100-0-0
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryErodeImageFilterTest-100-0-0.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-100-0-0.png
    itkGPUBinaryErodeImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-100-0-0.png 100 0 0 10)
itk_add_test(NAME itkGPUBinaryErodeImageFilterTest-100-0-1
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryErodeImageFilterTest-100-0-1.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-100-0-1.png
    itkGPUBinaryErodeImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-100-0-1.png 100 0 1 10)
itk_add_test(NAME itkGPUBinaryErodeImageFilterTest-100-150-0
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryErodeImageFilterTest-100-150-0.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-100-150-0.png
    itkGPUBinaryErodeImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-100-150-0.png 100 150 0 10)
itk_add_test(NAME itkGPUBinaryErodeImageFilterTest-100-150-1
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryErodeImageFilterTest-100-150-1.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-100-150-1.png
    itkGPUBinaryErodeImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-100-150-1.png 100 150 1 10)
itk_add_test(NAME itkGPUBinaryErodeImageFilterTest-200-0-0
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryErodeImageFilterTest-200-0-0.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-200-0-0.png
    itkGPUBinaryErodeImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-200-0-0.png 200 0 0 10)
itk_add_test(NAME itkGPUBinaryErodeImageFilterTest-200-0-1
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryErodeImageFilterTest-200-0-1.png}
             ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-200-0-1.png
    itkGPUBinaryErodeImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-200-0-1.png 200 0 1 10)
itk_add_test(NAME itkGPUBinaryErodeImageFilterTest-200-150-0
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryErodeImageFilterTest-200-150-0.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-200-150-0.png
    itkGPUBinaryErodeImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-200-150-0.png 200 150 0 10)
itk_add_test(NAME itkGPUBinaryErodeImageFilterTest-200-150-1
      COMMAND ITKGPUBinaryMorphologyTestDriver
    --compare DATA{${ITK_DATA_ROOT}/Baseline/BasicFilters/itkBinaryErodeImageFilterTest-200-150-1.png}
              ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-200-150-1.png
    itkGPUBinaryErodeImageFilterTest3 DATA{${ITK_DATA_ROOT}/Input/2th_cthead1.png} ${ITK_TEST_OUTPUT_DIR}/itkGPUBinaryErodeImageFilterTest-200-150-1.png 200 150 1 10)
