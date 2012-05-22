/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2009 Soeren Sonnenburg
 * Written (W) 1999-2008 Gunnar Raetsch
 * Written (W) 2011 Heiko Strathmann
 * Copyright (C) 1999-2009 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _BINARY_LABELS__H__
#define _BINARY_LABELS__H__

#include <shogun/lib/common.h>
#include <shogun/io/File.h>
#include <shogun/labels/LabelTypes.h>
#include <shogun/labels/DenseLabels.h>

namespace shogun
{
	class CFile;
	class CDenseLabels;

/** @brief Binary Labels for binary classification 
 *
 * valid values for labels are +1/-1
 */
class CBinaryLabels : public CDenseLabels
{
	public:
		/** default constructor */
		CBinaryLabels();

		/** constructor
		 *
		 * @param num_labels number of labels
		 */
		CBinaryLabels(int32_t num_labels);

		/** constructor
		 * sets confidences from src vector
		 * sets labels with sign of src elements with added threshold
		 *
		 * @param src labels to set
		 * @param threshold threshold
		 */
		CBinaryLabels(SGVector<float64_t> src, float64_t threshold=0.0);

		/** constructor
		 *
		 * @param loader File object via which to load data
		 */
		CBinaryLabels(CFile* loader);

		/** helper method used to specialize a base class instance
		 *
		 * @param base_labels its dynamic type must be CBinaryLabels
		 */
		static CBinaryLabels* obtain_from_generic(CLabels* base_labels);

		/** Make sure the label is valid, otherwise raise SG_ERROR.
		 *
		 * possible with subset
         *
         * @param context optional message to convey the context
		 */
		virtual void ensure_valid(const char* context=NULL);

		/** get label type
		 *
		 * @return label type binary
		 */
		virtual ELabelType get_label_type();

};
}
#endif
