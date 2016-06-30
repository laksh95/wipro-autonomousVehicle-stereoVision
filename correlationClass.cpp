#include <iostream>
#include<math.h>
using namespace std;
/************************************************
To compute Correlation function, first calculate
standard deviation, vairation, co variance.
************************************************/
class StandardDeviation
{
	int max;
 	double value[640];
	double mean;
 public:
	StandardDeviation()
	{

	}
	double calculateMean()
	{
		double sum=0;
		for(int i=0;i<max;i++)
			sum+=value[i];
		return sum/max;
	}	 
	double calculateVariance()
	{
		mean=calculateMean();
		double temp;
		for(int i=0;i<max;i++)
			tmp+=((value[i] - mean)*(value[i]-mean));
		return  temp/max;
	}
	double calculatesampleVariance()
	{
		mean=calculateMean();
		double temp;
		for(int i=0;i<max;i++)
			tmp+=((value[i] - mean)*(value[i]-mean));
		return  temp/(max-1);
	}
	int setValues(double *p, int count)
	{
		max=count;
		for(int i=0;i<max;i++)
			value[i]=p[i];
		return 1;
	}
	double calculateStandardDeviation()
	{
		return sqrt(calculateVariance());
	}
	double calculateSampleStandardDeviation()
	{
		return sqrt(calculateSampleVariance());
	}
};
class Correlation
{
	double left[640];
	double right[[640];
	int max;
	StandardDeviation l;
	StandardDeviation r;
 public:
	void setValues(double *p,double *q, int count)
	{
		max=count;
		for(int i=0;i<max;i++)
		{
			left[i]=p[i];
			right[i]=r[i];
		}
		l.setValues(left,count);
		r.setValues(right,count);
	}
	double calculateCoVariance()
	{
		double lmean=l.calculateMean();
		double rmean=r.calculateMean();
		double tmp=0;
		for(int i=0;i<max;i++)
		{
			tmp= tmp + (left[i]-lmean)*(right[i]-rmean)
		}		
		return tmp/max;
	}
	double calculateCorrelation()
	{
		double cov=calculateCorrelation();
		double correlation = cov/((l.calculateStandardDevation)*(r.calculateStandardDevation));
		return correlation;
	}
};
/************************************************
Convert image to 2-D double array, to mke it easy
to perform computations upon.
************************************************/
class image2D
{
	Mat img;
	double **m;	
/*	image2D(Mat img)
	{
		this->img=img;
		m=new double* [img.rows];
		for(int i=0;i<img.rowd;i++)
		{
			m[i]=new double[img.cols];
			for(int j=0;j<img.cols;j++)
			{
				m[i][j]=img.at(i,j);
			}
		}
	}*/
	void setImage(Mat img)
	{	
		this->img=img;
		m=new double* [img.rows];
		for(int i=0;i<img.rowd;i++)
		{
			m[i]=new double[img.cols];
			for(int j=0;j<img.cols;j++)
			{
				m[i][j]=img.at(i,j);
			}
		}
	}
	double **getMatrix() const
	{
		return m;
	}
	
	~image2D()
	{
		for(int i=0;i<img.rows;i++)
		{
			delete [] m[i];
		}
		delete []m;
	}
};
/**************************************************
Load the images. Input: Path of the image
**************************************************/
class Input
{
	Mat imgl;
	Mat imgr;
	
 public:
	void setImage(string left_path,string right_path)
	{
		imgl=open(left_path);
		imgr=open(right_path);
	}
};
int main()
{
	Correlation calc;
	string left_path,rigth_path;
	cout<<"Enter the path for the left and the right images: "<<endl;
	cin>>left_path>>right_path;
	Input input;
	input.setImage(left_path,right_path);
    {	
        printf("\n\nZero Correlation and Covariance Data Set\n");
        double xarr[] = { 8, 6, 4, 6, 8 };
        double yarr[] = { 10, 12, 14, 16, 18 };
        calc.SetValues(xarr,yarr,sizeof(xarr) / sizeof(xarr[0]));
        printf("Covariance = %.10lf\n", calc.Calculate_Covariance());
        printf("Correlation = %.10lf\n", calc.Calculate_Correlation());
    }
    {
        printf("\n\nPositive Correlation and Low Covariance Data Set\n");
        double xarr[] = { 0, 2, 4, 6, 8 };
        double yarr[] = { 6, 13, 15, 16, 20 };
        calc.SetValues(xarr,yarr,sizeof(xarr) / sizeof(xarr[0]));
        printf("Covariance = %.10lf\n", calc.Calculate_Covariance());
        printf("Correlation = %.10lf\n", calc.Calculate_Correlation());
    }
    {
        printf("\n\nNegative Correlation and Low Covariance Data Set\n");
        double xarr[] = { 8, 6, 4, 2, 0 };
        double yarr[] = { 6, 13, 15, 16, 20 };
        calc.SetValues(xarr,yarr,sizeof(xarr) / sizeof(xarr[0]));
        printf("Covariance = %.10lf\n", calc.Calculate_Covariance());
        printf("Correlation = %.10lf\n", calc.Calculate_Correlation());
    } 
    {
        printf("\n\nPositive Correlation and High Covariance Data Set\n");
        double xarr[] = { 8, 6, 4, 2, 0 };
        double yarr[] = { 1006, 513, 315, 216, 120 };
        calc.SetValues(xarr,yarr,sizeof(xarr) / sizeof(xarr[0]));
        printf("Covariance = %.10lf\n", calc.Calculate_Covariance());
        printf("Correlation = %.10lf\n", calc.Calculate_Correlation());
    }
    {
        printf("\n\nNegative Correlation and High Covariance Data Set\n");
        double xarr[] = { 8, 6, 4, 2, 0 };
        double yarr[] = { 120, 216, 315, 513, 1006 };
        calc.SetValues(xarr,yarr,sizeof(xarr) / sizeof(xarr[0]));
        printf("Covariance = %.10lf\n", calc.Calculate_Covariance());
        printf("Correlation = %.10lf\n", calc.Calculate_Correlation());
    }
}
