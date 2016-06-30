#include <siostream>
#include <cmath>
#include <cv2/cv.h>
using namespace cv;
using namespace std;
Mat imgl,imgr;
double intensity(double img[][5])
{
		double mean,sum=0;
		int i,j;
		for(i=0;i,5;i++)
			for(j=0;j<5;j++)
				sum+=img[i][j];
		mean=(double)sum/25;
		return mean;
}
/**************************************************************************
Make a window arround the pixel, 5X5 window to calculate correlation value.
**************************************************************************/
double **window(int i,int j,Mat img)
{
	double **arr = 0.0;
	arr = new double[5];
	int a=0,b=0;
	for(int x=0;x<5;x++)
		arr[x]=new double[5];
	for(int x=i-2;x<i+2;x++)
	{
		for(int y=j-2;y<j+2;y++)
		{
			arr[a][b]=img[x][y];
			b+=1;
		}
		a+=1;
		b=0;
	}
	return arr;	
}
/**************************************************************************
Add 2 rows and cols with -1 value on top,bottom,left and right of the image.
To make window easily for each and every pixel
***************************************************************************/
double **imageMatrix(Mat img)	
{
	double **x=0;
	x=new double[img.rows+2]
	for(int i=0;i<img.rows+2;i++)
	{
		x[i]=img.cols+2;
	}
	for(int i=0;i<img.rows+2;i++)
	{
		for(int j=0;<2;++)
			x[i][j]=-1;
		for(int j=img.cols;j<img.cols+2;j++)
			x[i][j]=-1;
	}
	for(int i=0;i<img.cols;i++)
	{
		for(int j=0;j<2;j++)
			x[j][i]=-1;
		for(int =img.rows;i<img.rows+2;++)
			x[j][i]=-1;
	}
	for(int i=2;i<img.rows+2;i++)
	{
		for(int j=2;j<img.cols+2;j++)
			x[i][j]=img[i][j];
	}
	return x;
	
}
/****************************************************************
Find the correlation value to compute the disparity of each pixel
****************************************************************/
double correlationCoefficient(int x,int y)
{
	itn i,j;
	double a,b,jnsq,jnsum=0,jdsq1,jdsq2,jdsum1=0,jdsum2=0,numerator=0,densum1=0,densum2=0,denominator,correlation;
	double imr[][5];
	
	for(i=x-2;i<x+2;i++){
		for(j=y-2;j<y+2;j++)
		{
			a=imgl[x][y]-mean(iml);
			b=mean(imgr);
			jnsq=pow((a-b),2);
			jnsum+=jnsq;
			jdsq1=pow(a,2);
			jdsq2=pow(b,2);
			jdsum1+=jdsq1;
			jdsum2+=jdsq2;
		}
		numerator+=jnsum;
		densum1+=jdsum1;
		densum2+=jdsum2;
	}
	denominator=sqrt(densum1) * sqrt(densum2);
	if(denominator!=0){
		correlation=numerator/denominator;
		return correlation;
	}
	else
		return 0;
}
/*************************************************
find the max correlation value of the row in image
*************************************************/
double findMax(double correlation[], int l)
{
	double max=correlation[0];
	for(int i=0;i<l;i++)
	{
		if(max<correlation[i])
			max=correlation[i];
	}
	return max;
}
void match(Mat imgl,Mat imr, double max)
{
	for(int i=0;i<imgl,cols;i++)
	{
		-
	}
}
int main()
{
	imgl=imread('',CV_LOAD_IMAGE_GRAYSCALE);
	imgr=imread('',CV_LOAD_IMAGE_GRAYSCALE);
	if(!imgl.data || !imgr.data)
	{
		cout<<"Images cannot be loaded."<<endl;
		return -1;
	}
	imgl=imageMatrix(imgl);
	imgr=imageMatrix(imgr);
	double correlation[640];
	int l=0;
	double iml[][5],imr[][5],max;
	for(int i=2;i<imgl.rows;i++)
	{
		l=0;
		for(int j=2;j<imgl.cols;j++)
		{
			for(int k=2;k<img.cols+2;k++)
			{
				makeWindow(i,k,imgl);
				makeWindow(i,k,imgr);
				correlation[l++]=correlationCoefficient(iml,imr);
			}
		}
		max=findMax(correlation,l);
		match(imgl,imgr,max);
		
	}	
}
