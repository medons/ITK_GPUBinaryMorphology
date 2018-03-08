/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkGPUImage.h"
#include "itkGPUBinaryDilateImageFilter.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkFilterWatcher.h"
#include "itkImageFileReader.h"


int itkGPUBinaryDilateImageFilterTest(int, char* [] )
{
  unsigned int i;

  // Define the dimension of the images
  const unsigned int myDimension = 2;

  // Define the values of the input images
  const unsigned short fgValue = 255;
  const unsigned short bgValue = 0;

  // Declare the types of the images
  typedef itk::GPUImage<unsigned short, myDimension>  myImageType;

  // Declare the type of the index to access images
  typedef itk::Index<myDimension>         myIndexType;

  // Declare the type of the size
  typedef itk::Size<myDimension>          mySizeType;

  // Declare the type of the Region
  typedef itk::ImageRegion<myDimension>        myRegionType;

  // Create an image
  myImageType::Pointer inputImage  = myImageType::New();

  // Define their size, and start index
  mySizeType size;
  size[0] = 50;
  size[1] = 50;

  myIndexType start;
  start[0] = 0;
  start[1] = 0;

  myRegionType region;
  region.SetIndex( start );
  region.SetSize( size );

  // Initialize Image
  inputImage->SetRegions( region );
  inputImage->Allocate();

  // Declare Iterator types apropriated for each image
  typedef itk::ImageRegionIterator<myImageType>  myIteratorType;

  /*
  // Create one iterator for image (this is a light object)
  myIteratorType it( inputImage, inputImage->GetBufferedRegion() );

  // Initialize the content of Image
  std::cout << "Input image " << std::endl;
  inputImage->FillBuffer(bgValue);

  myImageType::IndexType ind;
  ind[0] = 10;
  ind[1] = 10;
  inputImage->SetPixel(ind, fgValue);
  ind[0] = 2;
  ind[1] = 2;
  inputImage->SetPixel(ind, fgValue);

  ind[0] = 19;
  ind[1] = 10;
  inputImage->SetPixel(ind, fgValue);

  ind[0] = 19;
  ind[1] = 0;
  inputImage->SetPixel(ind, fgValue);

  ind[0] = 19;
  ind[1] = 19;
  inputImage->SetPixel(ind, fgValue);

  ind[0] = 0;
  ind[1] = 19;
  inputImage->SetPixel(ind, fgValue);

  i = 0;
  it.GoToBegin();
  while ( !it.IsAtEnd() )
    {
    std::cout << it.Get() << "  ";
    ++it;

    if (++i % size[0] == 0)
      {
      std::cout << std::endl;
      }
    }
*/

  typedef itk::ImageFileReader< myImageType > ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( "/home/voxelmaster/CIGuide/hcktest.png" );
  reader->Update();

  myIteratorType it( reader->GetOutput(), reader->GetOutput()->GetBufferedRegion() );
  i = 0;
  it.GoToBegin();
  while ( !it.IsAtEnd() )
    {
    std::cout << it.Get() << "  ";
    ++it;

    if (++i % 50 == 0)
      {
      std::cout << std::endl;
      }
    }

  // Declare the type for the structuring element
  typedef itk::BinaryBallStructuringElement<unsigned short, myDimension>
    myKernelType;

  // Declare the type for the morphology Filter
  typedef itk::GPUBinaryDilateImageFilter<myImageType, myImageType, myKernelType>
    myFilterType;

  // Create the filter
  myFilterType::Pointer filter = myFilterType::New();
  FilterWatcher filterWatcher(filter);

  // Create the structuring element
  myKernelType ball;
  myKernelType::SizeType ballSize;
  ballSize[0] = 1;
  ballSize[1] = 4;
  ball.SetRadius(4);
  ball.CreateStructuringElement();

  ball.Print(std::cout);

  // Connect the input image
  //filter->SetInput( inputImage );
  filter->SetInput( reader->GetOutput() );
  filter->SetForegroundValue( fgValue );
  filter->SetBackgroundValue( bgValue );
  filter->SetDilateValue( fgValue );
  filter->SetKernel( ball );

  // Get the Smart Pointer to the Filter Output
  myImageType::Pointer outputImage = filter->GetOutput();


  // Test the itkGetMacro
  unsigned short fgValueR = filter->GetForegroundValue();
  std::cout << "filter->GetForegroundValue(): " << fgValueR << std::endl;

  unsigned short bgValueR = filter->GetBackgroundValue();
  std::cout << "filter->GetBackgroundValue(): " << bgValueR << std::endl;

  // Execute the filter
  try
    {

    filter->Update();
    // Create an iterator for going through the image output
    myIteratorType it2(outputImage, outputImage->GetBufferedRegion());

    //  Print the content of the result image
    std::cout << "Result " << std::endl;
    i=0;
    while( !it2.IsAtEnd() )
      {
      std::cout << it2.Get() << "  ";
      ++it2;

      if (++i % size[0] == 0)
	{
	std::cout << std::endl;
	}
      }
   }

  catch (itk::ExceptionObject& e)
    {
    std::cerr << "Exception caught during filter Update\n"  << e;
    return -1;
    }

  // All objects should be automatically destroyed at this point

  return EXIT_SUCCESS;

}
