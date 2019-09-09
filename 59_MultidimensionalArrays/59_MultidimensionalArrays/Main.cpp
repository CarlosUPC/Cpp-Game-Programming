#include <iostream>
//Arrays = a block of memory and the ebst way to dealing with them is using pointers

 //array of arrays = a collection of pointers each of them points to a block of mem(array)

int main()
{
	int* array = new int[50];//allocating 50 integers --> 200 bytes of mem

	int** a2d = new int*[50];//allocating 50 integer pointers --> 200 bytes of mem
	
	//buffer of pointers -- a pointer to a pointer to an integer. in other word, a pointer to an integer pointer, not an integer

	//we have an array that contains the memory locations of 50 arrays
	for (int i = 0; i < 50; i++)
		a2d[i] = new int[50];

	//access
	a2d[0][0] = 0;
	//or
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			a2d[y][x] = 2;
		}

	}

	//delete each block of mem and buffer of pointers

	for (int i = 0; i < 50; i++)
		delete[] a2d[i];

	delete[] a2d;

	//3 dimensional array
	int*** a3d = new int**[50];

	for (int i = 0; i < 50; i++) {
		a3d[i] = new int*[50];
		for (int j = 0; j < 50; i++) {
			//a3d[i][j] = new int[50];
		//or
			int** ptr = a3d[i];
			ptr[j] = new int[50];
		}
	}

	//access to a block of mem
	a3d[0][0][0] = 0;

	//u are creating x buffers of mem separate randomly and arent in a row. ISSUE, cause if u wanna access each block of mem u need to jump into their buffers on mem places and that results in a cache miss. we are wasting time fetching that from our RAM, it will slower iterate through these 200 bytes of mem

	//optimize ur access data storage code and store close together, ur program will perform faster

	//avoid a2d or a3d and use always an a1d to allocate all bytes u need in a row to run ur code faster
}