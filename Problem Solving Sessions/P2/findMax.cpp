// Testing the code for the findMax function
int findMax (int arr[], int arrSize)
{
  int max = -1;
  for (int i = 0; i < arrSize; i++)
  {
    // cout << arr[i] << " ";
    // cout << "Pre-loop max: " << max;
    if (arr[i] >= arr[max])
    {
      max = i;
    }
  }
  // cout << endl;
  return max;
}