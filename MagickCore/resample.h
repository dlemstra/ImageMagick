/*
  Copyright 1999-2014 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    http://www.imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickCore graphic resample methods.
*/
#ifndef _MAGICKCORE_RESAMPLE_H
#define _MAGICKCORE_RESAMPLE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "MagickCore/cache-view.h"

/*
  WARNING:  The order of this table must also match the order of a table
  located in AcquireResizeFilter() in "resize.c" otherwise the users filter
  will not match the actual filter that is setup.
*/
typedef enum
{
  UndefinedFilter,
  PointFilter,
  BoxFilter,
  TriangleFilter,
  HermiteFilter,
  HannFilter,
  HammingFilter,
  BlackmanFilter,
  GaussianFilter,
  QuadraticFilter,
  CubicFilter,
  CatromFilter,
  MitchellFilter,
  JincFilter,
  SincFilter,
  SincFastFilter,
  KaiserFilter,
  WelchFilter,
  ParzenFilter,
  BohmanFilter,
  BartlettFilter,
  LagrangeFilter,
  LanczosFilter,
  LanczosSharpFilter,
  Lanczos2Filter,
  Lanczos2SharpFilter,
  RobidouxFilter,
  RobidouxSharpFilter,
  CosineFilter,
  SplineFilter,
  LanczosRadiusFilter,
  SentinelFilter  /* a count of all the filters, not a real filter */
} FilterTypes;

/*
  Backward compatibility for the more correctly named Jinc Filter.  Original
  source of this filter is from "zoom" but it refers to a reference by Pratt,
  who does not actualy name the filter.

  also miss-spellings of common filters
*/
#define BesselFilter  JincFilter
#define WelshFilter   WelchFilter
#define HanningFilter HannFilter

typedef struct _ResampleFilter
  ResampleFilter;

extern MagickExport MagickBooleanType
  ResamplePixelColor(ResampleFilter *,const double,const double,
    PixelInfo *,ExceptionInfo *),
  SetResampleFilterInterpolateMethod(ResampleFilter *,
    const PixelInterpolateMethod),
  SetResampleFilterVirtualPixelMethod(ResampleFilter *,
    const VirtualPixelMethod);

extern MagickExport ResampleFilter
  *AcquireResampleFilter(const Image *,ExceptionInfo *),
  *DestroyResampleFilter(ResampleFilter *);

extern MagickExport void
  ScaleResampleFilter(ResampleFilter *,const double,const double,const double,
    const double),
  SetResampleFilter(ResampleFilter *,const FilterTypes);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
