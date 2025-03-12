Got it! Here's a Confluence page section focusing on your static validations, including the table of completed forms:

**Page Title: PDF Form Validation Tool - Static Validation Progress**

**Static Validation Overview**

The static validation component of our PDF Form Validation Tool focuses on ensuring the consistency and accuracy of fixed content within onboarding PDF forms. This is crucial for maintaining compliance and brand standards. Our approach involves a line-by-line comparison of extracted text from new forms against established templates, with a robust system for handling variations and "ignore patterns."

**Static Validation Process**

1.  **Text Extraction:**
    * We extract text from both the newly generated PDF form and the corresponding template PDF.
2.  **Text Normalization:**
    * To ensure accurate comparison, we remove any non-Latin characters from the extracted text using the regular expression `replaceAll("[^ -~\n]","")`. This eliminates potential issues with encoding and special characters.
3.  **Ignore Pattern Removal:**
    * We apply a set of predefined "ignore patterns" to both the new and template text. These patterns represent sections of the form that are expected to vary or are not critical for static validation (e.g., date stamps, form version numbers).
4.  **Line-by-Line Comparison:**
    * The remaining lines of text are compared one by one. Any discrepancies are flagged as validation failures.

**Completed Static Validations**

We have successfully implemented and validated the static content for the following onboarding forms:

| Form Number/Name | Status     |
| :---------------- | :--------- |
| 228               | Completed  |
| MKT6748           | Completed  |
| 227               | Completed  |
| 231               | Completed  |
| 132               | Completed  |
| 087               | Completed  |
| 215               | Completed  |
| 50                | Completed  |
| 037               | Completed  |
| 236               | Completed  |
| Operating Rules    | Completed  |

**Implementation Details**

* We have created a comprehensive set of "ignore patterns" tailored to each form, allowing for accurate and reliable comparisons.
* Template forms have been established and stored for each form type, serving as the baseline for validation.
* The system is designed to provide clear and actionable reports on any detected discrepancies.

**Next Steps (Static Validation)**

* Maintain the ignore pattern list, and template forms.
* Automate the reporting of the validation results.
* Improve the speed of the comparison.
