#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <assert.h>
using namespace std;

long mergeInvert(vector<int>&nums,int start,int middle,int end)
{
  long count=0;
  int i=start,j=middle;
  vector<int> c;
  while (i<middle && j<end)
  {
    if (nums[i]<nums[j])
    {
      c.push_back(nums[i]);
      i++;
    }
    else
    {
      c.push_back(nums[j]);
      j++;
      count+=(middle-i);
    }
  }
  while (i<middle) c.push_back(nums[i++]);
  while (j<end) c.push_back(nums[j++]);
  assert(c.size()==(end-start));
  for (int i=start;i<end;i++) nums[i]=c[i-start];
  return count;
}

long mergeSort(vector<int>& nums,int start,int end)
{
  if (end-start>1)
  {
    long middle = (start + end)/2;;
    long left = mergeSort(nums,start,middle);
    long right = mergeSort(nums,middle,end);
    long extra = mergeInvert(nums,start,middle,end);
    return left + right + extra;
  }
  return 0;
}





int main()
{
  int tmp,n=0;
  vector<int> nums;
  while (scanf("%d",&tmp)!=EOF)
  {
    nums.push_back(tmp);
    n++;
  }
  printf("numbers: %d\n",n);

  long count=mergeSort(nums,0,n);
  printf("%ld\n",count);
  return 0;
}
