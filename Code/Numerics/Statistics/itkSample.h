/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkSample.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkSample_h
#define __itkSample_h

#include "itkMacro.h"
#include "itkPoint.h"
#include "itkSize.h"
#include "itkObject.h"

namespace itk{ 
  namespace Statistics{

/** \class Sample 
 *  \brief Sample defines common iterfaces for each subclasses
 *
 * A measurement vector is a vector of different types of values. For example,
 * users might have an image with each pixel have a gray level intensity value
 * and a gradient magnitude. In this example, user think each pixel as a 
 * measurement vector that has two types of values, intensity and gradient
 * magnitude. In this sense, the meaning of "measurement" can be interchaneable 
 * with "measurement".
 * 
 * The primary purpose of Sample clases are storing such 
 * measurement vectors and providing different types of element access methods.
 *
 * The "TMeasurement" template argument defines the type of each values
 * in a measurement vector. The "VMeasurementVectorSize" template argument 
 * defines 
 * the number of elements in a measurement vector. The type of measurement 
 * vector 
 * is fixed as ITK Point. The resulting measurement vector type is 
 * Point< TMeasurement, VMeasurementVectorSize >.
 *
 * There are two common ways of accessing data. First, users can use 
 * an "InstanceIdentifier", say 'id' which is sequential index of 
 * measurement vectors to access a measurement vector in a container. 
 * Second, users can access a measurement value using dimension and 
 * the index of a measurement value, say 'n' in that dimension. The 'id' and 'n'
 * is equal in the ListSample classes. However, in Histogram class, its
 * different. See Histogram. For algorithms using these indexes, there are
 * methods to get the length of each dimension, GetSize() and 
 * GetSize(dimension). See each method's comment.
 *
 * Users may need to know two other groups of methods to fully utilize
 * Sample. One group of methods is about frequency of measurement
 * vectors. In Histogram classes, you can use such methods to get/set the
 * frequency of each measurement vector. The other group of methods is about
 * characteristics of each subclasses of this class. If user want to 
 * create or know the characteristics of a subclass, use them. The set of
 * characteristics tell that if the data is sorted (true for Histogram),
 * if the each measurement vector is unique (true for Histogram), and if the
 * container supports "meaningful" frequency interfaces. In ListSample
 * classes, users cannot set frequency, and GetFrequency() methods return 
 * one if the element exists, else zero. So, currently ListSample's
 * supporting frequency is set to false. 
 */

template < class TMeasurement = float, 
  unsigned int VMeasurementVectorSize = 1 > 
class ITK_EXPORT Sample : public Object
{
public:
  /** Standard class typedefs */
  typedef Sample  Self;

  /** Run-time type information (and related methods) */
  itkTypeMacro(Sample, Object);

  /** MeasurementVector typedef support */ 
  typedef FixedArray<TMeasurement, VMeasurementVectorSize> MeasurementVectorType ;

  /** typedef for each element in a measurement vector*/ 
  typedef TMeasurement MeasurementType ;

  /** Alias for the number of measurement vector components */
  enum { MeasurementVectorSize = VMeasurementVectorSize } ;

  /** frequency value typedef*/
  typedef float FrequencyType ;

  /** Instance Identifier typedef support
   * this identifier will be unique sequential id for each measurement vector
   * in a Sample subclass.*/ 
  typedef unsigned long InstanceIdentifier ;

  /** size value type */
  typedef Size< VMeasurementVectorSize > SizeType ;
  typedef typename SizeType::SizeValueType SizeValueType ;

  /** returns SizeType object whose each element is the number of
   * elements in each dimension*/
  virtual SizeType GetSize() = 0 ;
  
  /** returns SizeValueType value that is the number of elements in the
   * 'dimension' dimension.*/
  virtual SizeValueType GetSize(unsigned int dimension) = 0 ;

  virtual size_t GetNumberOfInstances() = 0 ;

  /** retunrs the measurement of the instance which is identified by the 'id'*/
  virtual MeasurementVectorType GetMeasurementVector(const InstanceIdentifier id)  = 0 ;

  /** returns the frequency of the instance which is identified by the 'id'*/
  virtual FrequencyType GetFrequency(const InstanceIdentifier id)  = 0 ;

  /** returns the measurement element which is the 'n'-th element 
   * in the 'd' dimension of the measurement vector*/
  virtual MeasurementType GetMeasurement(const unsigned int d, 
                                               const unsigned long n) = 0 ;
  
  /** returns the frequency of the 'n'-th element in the 'd' dimension * of the measurement vector*/
  virtual FrequencyType GetFrequency(const unsigned int d,
                                     const unsigned long n)  = 0 ;

  /** returns the total frequency for the 'd' dimension*/
  virtual FrequencyType GetTotalFrequency(const unsigned int d)  = 0 ;

  /** if a subclass of this class has its data sorted, return true* else, false.*/
  bool IsSorted() { return m_Sorted ; }

  /** sets the Sorted flag*/
  void SetSortedFlag(bool flag) { m_Sorted = flag ; }

  /** if a subclass of this class has frequency values associated with* each measurement and support GetFrequency mehtod, returns true,* else, false.*/
  bool IsSupportingFrequency() { return m_SupportingFrequency ; }

  /** sets the SupportingFrequency flag*/
  void SetSupportingFrequencyFlag(bool flag) { m_SupportingFrequency = flag ; }

  /** if a subclass of this class allowes duplicate measurement vectors, returns* true, else, false.*/
  bool IsAllowingDuplicates() { return m_AllowingDuplicates ; }

  /** sets the AllowingDuplicates flag*/
  void SetAllowingDuplicatesFlag(bool flag) { m_AllowingDuplicates = flag ; }
  
protected:
  Sample() {}
  virtual ~Sample() {}
  void PrintSelf(std::ostream& os, Indent indent) const
  {
    Superclass::PrintSelf(os,indent);

    os << indent << "Sorted: " << m_Sorted << std::endl ;
    os << indent << "SupportingFrequency: " << m_SupportingFrequency
       << std::endl ;
    os << indent << "AllowingDuplicates: " << m_AllowingDuplicates 
       << std::endl ;
  }

  
private:
  Sample(const Self&) ; //purposely not implemented
  void operator=(const Self&) ; //purposely not implemented

  bool m_Sorted ;
  bool m_SupportingFrequency ;
  bool m_AllowingDuplicates ;
} ; // end of class


  } // end of namespace Statistics 
} // end of namespace itk

#endif
