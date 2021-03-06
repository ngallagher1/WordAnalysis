/*
 *
 *  Copyright (C) 1996-2002, OFFIS
 *
 *  This software and supporting documentation were developed by
 *
 *    Kuratorium OFFIS e.V.
 *    Healthcare Information and Communication Systems
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *  THIS SOFTWARE IS MADE AVAILABLE,  AS IS,  AND OFFIS MAKES NO  WARRANTY
 *  REGARDING  THE  SOFTWARE,  ITS  PERFORMANCE,  ITS  MERCHANTABILITY  OR
 *  FITNESS FOR ANY PARTICULAR USE, FREEDOM FROM ANY COMPUTER DISEASES  OR
 *  ITS CONFORMITY TO ANY SPECIFICATION. THE ENTIRE RISK AS TO QUALITY AND
 *  PERFORMANCE OF THE SOFTWARE IS WITH THE USER.
 *
 *  Module:  dcmimgle
 *
 *  Author:  Joerg Riesmeier
 *
 *  Purpose: DiCubicSpline Function/Interpolation (Header/Implementation)
 *
 */


#ifndef __DISPLINT_H
#define __DISPLINT_H

#include "osconfig.h"


// SunCC 4.x does not support default values for template types :-/
#define T3_ double


/*------------------*
 *  template class  *
 *------------------*/

/** Template class for cubic spline interpolation
 */
template <class T1, class T2 /*, class T3 = double*/>
class DiCubicSpline
{
 public:

    /** calculate spline function for given points.
     *  T1  = type of x coordinates
     *  T2  = type of y coordinates
     *  T3_ = type of y coordinates of the spline function
     *
     ** @param  x    array with x coordinates of given points
     *  @param  y    array with y coordinates of given points
     *  @param  n    number of entries in array (= points)
     *  @param  y2   array used to store the resulting spline function (used for CubicSplineInterpolation)
     *  @param  yp1  first derivative of the interpolating function at point 1
     *  @param  ypn  first derivative of the interpolating function at point n
     *
     ** @return true if successful, false otherwise
     */
    static int Function(const T1 *x,
                        const T2 *y,
                        const unsigned int n,
                        T3_ *y2,
                        const T3_ yp1 = 1.0e30,
                        const T3_ ypn = 1.0e30)
    {
        if ((x != NULL) && (y != NULL) && (n > 0) && (y2 != NULL))
        {
            T3_ *u = new T3_[n];                              // temporary vector
            if (u != NULL)
            {
                register unsigned int i;
                T3_ p, qn, sig, un;
                if (yp1 > 0.99e30)                          // ignore value for first derivative at point 1
                    y2[0] = u[0] = 0.0;
                else
                {
                    y2[0] = -0.5;
                    u[0] = (3.0 / ((T3_)x[1] - (T3_)x[0])) * (((T3_)y[1] - (T3_)y[0]) / ((T3_)x[1] - (T3_)x[0]) - yp1);
                }
                for (i = 1; i < n - 1; i++)
                {
                    sig = ((T3_)x[i] - (T3_)x[i - 1]) / ((T3_)x[i + 1] - (T3_)x[i - 1]);
                    p = sig * y2[i - 1] + 2.0;
                    y2[i] = (sig - 1.0) / p;
                    u[i] = ((T3_)y[i + 1] - (T3_)y[i]) / ((T3_)x[i + 1] - (T3_)x[i]) - ((T3_)y[i] - (T3_)y[i - 1]) / ((T3_)x[i] - (T3_)x[i - 1]);
                    u[i] = (6.0 * u[i] / ((T3_)x[i + 1] - (T3_)x[i - 1]) - sig * u[i - 1]) / p;
                }
                if (ypn > 0.99e30)                          // ignore value for first derivative at point 1
                    qn = un = 0.0;
                else
                {
                    qn = 0.5;
                    un = (3.0 / ((T3_)x[n - 1] - (T3_)x[n - 2])) * (ypn - ((T3_)y[n - 1] - (T3_)y[n - 2]) / ((T3_)x[n - 1] - (T3_)x[n - 2]));
                }
                y2[n - 1] = (un - qn * u[n - 2]) / (qn * y2[n - 2] + 1.0);
                for (i = n - 1; i > 0; i--)
                    y2[i - 1] = y2[i - 1] * y2[i] + u[i - 1];
                delete[] u;
                return 1;
            }
        }
        return 0;
    }


    /** perform cubic spline interpolation for given points.
     *  T1  = type of x coordinates
     *  T2  = type of y coordinates
     *  T3_ = type of y coordinates of the spline function
     *
     ** @param  xa   array with x coordinates of given points
     *  @param  ya   array with y coordinates of given points
     *  @param  y2a  array used to store the resulting spline function (calculated by CubicSplineFunction)
     *  @param  na   number of entries in above arrays (xa, ya and y2a)
     *  @param  x    array with x coordinates of points to be interpolated
     *  @param  y    array used to store interpolated values
     *  @param  n    number of entries in above array (x and y)
     *
     ** @return true if successful, false otherwise
     */
    static int Interpolation(const T1 *xa,
                             const T2 *ya,
                             const T3_ *y2a,
                             const unsigned int na,
                             const T1 *x,
                             T2 *y,
                             const unsigned int n)
    {
        if ((xa != NULL) && (ya != NULL) && (y2a != NULL) && (na > 0) && (x != NULL) && (y != NULL) && (n > 0))
        {
            register unsigned int k, i;
            register unsigned int klo = 0;
            register unsigned int khi = na - 1;
            T3_ h, b, a;
            for (i = 0; i < n; i++)
            {
                if ((xa[klo] > x[i]) || (xa[khi] < x[i]))       // optimization
                {
                    klo = 0;
                    khi = na - 1;
                }
                while (khi - klo > 1)                           // search right place in the table, if necessary
                {
                    k = (khi + klo) >> 1;
                    if (xa[k] > x[i])
                        khi = k;
                    else
                        klo = k;
                }
                if (xa[khi] == x[i])                            // optimization: use known values
                    y[i] = ya[khi];
                else
                {
                    h = (T3_)xa[khi] - (T3_)xa[klo];
                    if (h == 0.0)                               // bad xa input, values must be distinct !
                        return 0;
                    a = ((T3_)xa[khi] - (T3_)x[i]) / h;
                    b = ((T3_)x[i] - (T3_)xa[klo]) / h;
                    y[i] = (T2)(a * (T3_)ya[klo] + b * (T3_)ya[khi] + ((a * a * a - a) * y2a[klo] + (b * b * b - b) * y2a[khi]) * (h * h) / 6.0);
                }
            }
            return 1;
        }
        return 0;
    }
};


#endif
