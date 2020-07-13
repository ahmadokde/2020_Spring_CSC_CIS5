/*
 * Function template to dynamically allocate arrays of any type
 *
 * Function Name: createArray
 * Description:   Dynamically allocates an array of the template type with 'size' elements.
 *
 * Call:    createArray <type> (size, initValue);
 * Returns: a pointer to the new array .
 *
 */
template <class targetType>
targetType *createArray (int size, targetType initVal) {

  // allocate array and initialize to default value for the type
  targetType *newArray = new targetType [size] ();

  // Set every element to initVal
  for (int i = 0; i < size; i++)
    newArray[i] = initVal;

  return newArray;

}
