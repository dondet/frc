// COLUMN 1 = Position (rotations)
// COLUMN 2 = Velocity (rpm)
// COLUMN 3 = Duration (ms)
const int kBaselineBSz = 560;
const double kBaselineB[][3] = {
{0,	0	,10.0},
{2.38095238095238e-05,	0.285714285714286	,10.0},
{0.000107142857142857,	0.714285714285714	,10.0},
{0.000273809523809524,	1.28571428571429	,10.0},
{0.000547619047619048,	2	,10.0},
{0.000952380952380952,	2.85714285714286	,10.0},
{0.00151190476190476,	3.85714285714286	,10.0},
{0.00225,	5	,10.0},
{0.00319047619047619,	6.28571428571428	,10.0},
{0.00435714285714286,	7.71428571428572	,10.0},
{0.00577380952380952,	9.28571428571429	,10.0},
{0.00746428571428571,	11	,10.0},
{0.00945238095238095,	12.8571428571429	,10.0},
{0.0117619047619048,	14.8571428571429	,10.0},
{0.0144166666666667,	17	,10.0},
{0.0174404761904762,	19.2857142857143	,10.0},
{0.0208571428571429,	21.7142857142857	,10.0},
{0.0246904761904762,	24.2857142857143	,10.0},
{0.0289642857142857,	27	,10.0},
{0.033702380952381,	29.8571428571429	,10.0},
{0.0389285714285714,	32.8571428571429	,10.0},
{0.0446547619047619,	35.8571428571429	,10.0},
{0.0508809523809524,	38.8571428571429	,10.0},
{0.0576071428571429,	41.8571428571429	,10.0},
{0.0648333333333333,	44.8571428571429	,10.0},
{0.0725595238095238,	47.8571428571429	,10.0},
{0.0807857142857143,	50.8571428571429	,10.0},
{0.0895119047619048,	53.8571428571429	,10.0},
{0.0987380952380952,	56.8571428571429	,10.0},
{0.108464285714286,	59.8571428571429	,10.0},
{0.118690476190476,	62.8571428571429	,10.0},
{0.129416666666667,	65.8571428571429	,10.0},
{0.140642857142857,	68.8571428571429	,10.0},
{0.152369047619048,	71.8571428571429	,10.0},
{0.164595238095238,	74.8571428571429	,10.0},
{0.177321428571429,	77.8571428571429	,10.0},
{0.190547619047619,	80.8571428571429	,10.0},
{0.20427380952381,	83.8571428571429	,10.0},
{0.2185,	86.8571428571429	,10.0},
{0.23322619047619,	89.8571428571429	,10.0},
{0.248452380952381,	92.8571428571429	,10.0},
{0.264154761904762,	95.5714285714286	,10.0},
{0.280297619047619,	98.1428571428572	,10.0},
{0.296857142857143,	100.571428571429	,10.0},
{0.313809523809524,	102.857142857143	,10.0},
{0.331130952380952,	105	,10.0},
{0.348797619047619,	107	,10.0},
{0.366785714285714,	108.857142857143	,10.0},
{0.385071428571429,	110.571428571429	,10.0},
{0.403630952380952,	112.142857142857	,10.0},
{0.422440476190476,	113.571428571429	,10.0},
{0.44147619047619,	114.857142857143	,10.0},
{0.460714285714286,	116	,10.0},
{0.480130952380952,	117	,10.0},
{0.499702380952381,	117.857142857143	,10.0},
{0.519404761904762,	118.571428571429	,10.0},
{0.539214285714286,	119.142857142857	,10.0},
{0.559107142857143,	119.571428571429	,10.0},
{0.579059523809524,	119.857142857143	,10.0},
{0.599047619047619,	120	,10.0},
{0.619047619047619,	120	,10.0},
{0.639047619047619,	120	,10.0},
{0.659047619047619,	120	,10.0},
{0.679047619047619,	120	,10.0},
{0.699047619047619,	120	,10.0},
{0.719047619047619,	120	,10.0},
{0.739047619047619,	120	,10.0},
{0.759047619047619,	120	,10.0},
{0.779047619047619,	120	,10.0},
{0.799047619047619,	120	,10.0},
{0.819047619047619,	120	,10.0},
{0.839047619047619,	120	,10.0},
{0.859047619047619,	120	,10.0},
{0.879047619047619,	120	,10.0},
{0.899047619047619,	120	,10.0},
{0.919047619047619,	120	,10.0},
{0.939047619047619,	120	,10.0},
{0.959047619047619,	120	,10.0},
{0.979047619047619,	120	,10.0},
{0.999047619047619,	120	,10.0},
{1.01904761904762,	120	,10.0},
{1.03904761904762,	120	,10.0},
{1.05904761904762,	120	,10.0},
{1.07904761904762,	120	,10.0},
{1.09904761904762,	120	,10.0},
{1.11904761904762,	120	,10.0},
{1.13904761904762,	120	,10.0},
{1.15904761904762,	120	,10.0},
{1.17904761904762,	120	,10.0},
{1.19904761904762,	120	,10.0},
{1.21904761904762,	120	,10.0},
{1.23904761904762,	120	,10.0},
{1.25904761904762,	120	,10.0},
{1.27904761904762,	120	,10.0},
{1.29904761904762,	120	,10.0},
{1.31904761904762,	120	,10.0},
{1.33904761904762,	120	,10.0},
{1.35904761904762,	120	,10.0},
{1.37904761904762,	120	,10.0},
{1.39904761904762,	120	,10.0},
{1.41904761904762,	120	,10.0},
{1.43904761904762,	120	,10.0},
{1.45904761904762,	120	,10.0},
{1.47904761904762,	120	,10.0},
{1.49904761904762,	120	,10.0},
{1.51904761904762,	120	,10.0},
{1.53904761904762,	120	,10.0},
{1.55904761904762,	120	,10.0},
{1.57904761904762,	120	,10.0},
{1.59904761904762,	120	,10.0},
{1.61904761904762,	120	,10.0},
{1.63904761904762,	120	,10.0},
{1.65904761904762,	120	,10.0},
{1.67904761904762,	120	,10.0},
{1.69904761904762,	120	,10.0},
{1.71904761904762,	120	,10.0},
{1.73904761904762,	120	,10.0},
{1.75904761904762,	120	,10.0},
{1.77904761904762,	120	,10.0},
{1.79904761904762,	120	,10.0},
{1.81904761904762,	120	,10.0},
{1.83904761904762,	120	,10.0},
{1.85904761904762,	120	,10.0},
{1.87904761904762,	120	,10.0},
{1.89904761904762,	120	,10.0},
{1.91904761904762,	120	,10.0},
{1.93904761904762,	120	,10.0},
{1.95904761904762,	120	,10.0},
{1.97904761904762,	120	,10.0},
{1.99904761904762,	120	,10.0},
{2.01904761904762,	120	,10.0},
{2.03904761904762,	120	,10.0},
{2.05904761904762,	120	,10.0},
{2.07904761904762,	120	,10.0},
{2.09904761904762,	120	,10.0},
{2.11904761904762,	120	,10.0},
{2.13904761904762,	120	,10.0},
{2.15904761904762,	120	,10.0},
{2.17904761904762,	120	,10.0},
{2.19904761904762,	120	,10.0},
{2.21904761904762,	120	,10.0},
{2.23904761904762,	120	,10.0},
{2.25904761904762,	120	,10.0},
{2.27904761904762,	120	,10.0},
{2.29904761904762,	120	,10.0},
{2.31904761904762,	120	,10.0},
{2.33904761904762,	120	,10.0},
{2.35904761904762,	120	,10.0},
{2.37904761904762,	120	,10.0},
{2.39904761904762,	120	,10.0},
{2.41904761904762,	120	,10.0},
{2.43904761904762,	120	,10.0},
{2.45904761904762,	120	,10.0},
{2.47904761904762,	120	,10.0},
{2.49904761904762,	120	,10.0},
{2.51904761904762,	120	,10.0},
{2.53904761904762,	120	,10.0},
{2.55904761904762,	120	,10.0},
{2.57904761904762,	120	,10.0},
{2.59904761904762,	120	,10.0},
{2.61904761904762,	120	,10.0},
{2.63904761904762,	120	,10.0},
{2.65904761904762,	120	,10.0},
{2.67904761904762,	120	,10.0},
{2.69904761904762,	120	,10.0},
{2.71904761904762,	120	,10.0},
{2.73904761904762,	120	,10.0},
{2.75904761904762,	120	,10.0},
{2.77904761904762,	120	,10.0},
{2.79904761904762,	120	,10.0},
{2.81904761904762,	120	,10.0},
{2.83904761904762,	120	,10.0},
{2.85904761904762,	120	,10.0},
{2.87904761904762,	120	,10.0},
{2.89904761904762,	120	,10.0},
{2.91904761904762,	120	,10.0},
{2.93904761904762,	120	,10.0},
{2.95904761904762,	120	,10.0},
{2.97904761904762,	120	,10.0},
{2.99904761904762,	120	,10.0},
{3.01904761904762,	120	,10.0},
{3.03904761904762,	120	,10.0},
{3.05904761904762,	120	,10.0},
{3.07904761904762,	120	,10.0},
{3.09904761904762,	120	,10.0},
{3.11904761904762,	120	,10.0},
{3.13904761904762,	120	,10.0},
{3.15904761904762,	120	,10.0},
{3.17904761904762,	120	,10.0},
{3.19904761904762,	120	,10.0},
{3.21904761904762,	120	,10.0},
{3.23904761904762,	120	,10.0},
{3.25904761904762,	120	,10.0},
{3.27904761904762,	120	,10.0},
{3.29904761904762,	120	,10.0},
{3.31904761904762,	120	,10.0},
{3.33904761904762,	120	,10.0},
{3.35904761904762,	120	,10.0},
{3.37904761904762,	120	,10.0},
{3.39904761904762,	120	,10.0},
{3.41904761904762,	120	,10.0},
{3.43904761904762,	120	,10.0},
{3.45904761904762,	120	,10.0},
{3.47904761904762,	120	,10.0},
{3.49904761904762,	120	,10.0},
{3.51904761904762,	120	,10.0},
{3.53904761904762,	120	,10.0},
{3.55904761904762,	120	,10.0},
{3.57904761904762,	120	,10.0},
{3.59904761904762,	120	,10.0},
{3.61904761904762,	120	,10.0},
{3.63904761904762,	120	,10.0},
{3.65904761904762,	120	,10.0},
{3.67904761904762,	120	,10.0},
{3.69904761904762,	120	,10.0},
{3.71904761904762,	120	,10.0},
{3.73904761904762,	120	,10.0},
{3.75904761904762,	120	,10.0},
{3.77904761904762,	120	,10.0},
{3.79904761904762,	120	,10.0},
{3.81904761904762,	120	,10.0},
{3.83904761904762,	120	,10.0},
{3.85904761904762,	120	,10.0},
{3.87904761904762,	120	,10.0},
{3.89904761904762,	120	,10.0},
{3.91904761904762,	120	,10.0},
{3.93904761904762,	120	,10.0},
{3.95904761904762,	120	,10.0},
{3.97904761904762,	120	,10.0},
{3.99904761904762,	120	,10.0},
{4.01904761904762,	120	,10.0},
{4.03904761904762,	120	,10.0},
{4.05904761904762,	120	,10.0},
{4.07904761904762,	120	,10.0},
{4.09904761904762,	120	,10.0},
{4.11904761904762,	120	,10.0},
{4.13904761904762,	120	,10.0},
{4.15904761904762,	120	,10.0},
{4.17904761904762,	120	,10.0},
{4.19904761904762,	120	,10.0},
{4.21904761904762,	120	,10.0},
{4.23904761904762,	120	,10.0},
{4.25904761904762,	120	,10.0},
{4.27904761904762,	120	,10.0},
{4.29904761904762,	120	,10.0},
{4.31904761904762,	120	,10.0},
{4.33904761904761,	120	,10.0},
{4.35904761904761,	120	,10.0},
{4.37904761904761,	120	,10.0},
{4.39904761904761,	120	,10.0},
{4.41904761904761,	120	,10.0},
{4.43904761904761,	120	,10.0},
{4.45904761904761,	120	,10.0},
{4.47904761904761,	120	,10.0},
{4.49904761904761,	120	,10.0},
{4.51904761904761,	120	,10.0},
{4.53904761904761,	120	,10.0},
{4.55904761904761,	120	,10.0},
{4.57904761904761,	120	,10.0},
{4.59904761904761,	120	,10.0},
{4.61904761904761,	120	,10.0},
{4.63904761904761,	120	,10.0},
{4.65904761904761,	120	,10.0},
{4.67904761904761,	120	,10.0},
{4.69904761904761,	120	,10.0},
{4.71904761904761,	120	,10.0},
{4.73904761904761,	120	,10.0},
{4.75904761904761,	120	,10.0},
{4.77904761904761,	120	,10.0},
{4.79904761904761,	120	,10.0},
{4.8190476190476,	120	,10.0},
{4.8390476190476,	120	,10.0},
{4.8590476190476,	120	,10.0},
{4.8790476190476,	120	,10.0},
{4.8990476190476,	120	,10.0},
{4.9190476190476,	120	,10.0},
{4.9390476190476,	120	,10.0},
{4.9590476190476,	120	,10.0},
{4.9790476190476,	120	,10.0},
{4.9990476190476,	120	,10.0},
{5.0190476190476,	120	,10.0},
{5.0390476190476,	120	,10.0},
{5.0590476190476,	120	,10.0},
{5.0790476190476,	120	,10.0},
{5.0990476190476,	120	,10.0},
{5.1190476190476,	120	,10.0},
{5.1390476190476,	120	,10.0},
{5.1590476190476,	120	,10.0},
{5.1790476190476,	120	,10.0},
{5.1990476190476,	120	,10.0},
{5.2190476190476,	120	,10.0},
{5.2390476190476,	120	,10.0},
{5.2590476190476,	120	,10.0},
{5.27904761904759,	120	,10.0},
{5.29904761904759,	120	,10.0},
{5.31904761904759,	120	,10.0},
{5.33904761904759,	120	,10.0},
{5.35904761904759,	120	,10.0},
{5.37904761904759,	120	,10.0},
{5.39904761904759,	120	,10.0},
{5.41904761904759,	120	,10.0},
{5.43904761904759,	120	,10.0},
{5.45904761904759,	120	,10.0},
{5.47904761904759,	120	,10.0},
{5.49904761904759,	120	,10.0},
{5.51904761904759,	120	,10.0},
{5.53904761904759,	120	,10.0},
{5.55904761904759,	120	,10.0},
{5.57904761904759,	120	,10.0},
{5.59904761904759,	120	,10.0},
{5.61904761904759,	120	,10.0},
{5.63904761904759,	120	,10.0},
{5.65904761904759,	120	,10.0},
{5.67904761904759,	120	,10.0},
{5.69904761904759,	120	,10.0},
{5.71904761904759,	120	,10.0},
{5.73904761904758,	120	,10.0},
{5.75904761904758,	120	,10.0},
{5.77904761904758,	120	,10.0},
{5.79904761904758,	120	,10.0},
{5.81904761904758,	120	,10.0},
{5.83904761904758,	120	,10.0},
{5.85904761904758,	120	,10.0},
{5.87904761904758,	120	,10.0},
{5.89904761904758,	120	,10.0},
{5.91904761904758,	120	,10.0},
{5.93904761904758,	120	,10.0},
{5.95904761904758,	120	,10.0},
{5.97904761904758,	120	,10.0},
{5.99904761904758,	120	,10.0},
{6.01904761904758,	120	,10.0},
{6.03904761904758,	120	,10.0},
{6.05904761904758,	120	,10.0},
{6.07904761904758,	120	,10.0},
{6.09904761904758,	120	,10.0},
{6.11904761904758,	120	,10.0},
{6.13904761904758,	120	,10.0},
{6.15904761904758,	120	,10.0},
{6.17904761904758,	120	,10.0},
{6.19904761904758,	120	,10.0},
{6.21904761904757,	120	,10.0},
{6.23904761904757,	120	,10.0},
{6.25904761904757,	120	,10.0},
{6.27904761904757,	120	,10.0},
{6.29904761904757,	120	,10.0},
{6.31904761904757,	120	,10.0},
{6.33904761904757,	120	,10.0},
{6.35904761904757,	120	,10.0},
{6.37904761904757,	120	,10.0},
{6.39904761904757,	120	,10.0},
{6.41904761904757,	120	,10.0},
{6.43904761904757,	120	,10.0},
{6.45904761904757,	120	,10.0},
{6.47904761904757,	120	,10.0},
{6.49904761904757,	120	,10.0},
{6.51904761904757,	120	,10.0},
{6.53904761904757,	120	,10.0},
{6.55904761904757,	120	,10.0},
{6.57904761904757,	120	,10.0},
{6.59904761904757,	120	,10.0},
{6.61904761904757,	120	,10.0},
{6.63904761904757,	120	,10.0},
{6.65904761904757,	120	,10.0},
{6.67904761904756,	120	,10.0},
{6.69904761904756,	120	,10.0},
{6.71904761904756,	120	,10.0},
{6.73904761904756,	120	,10.0},
{6.75904761904756,	120	,10.0},
{6.77904761904756,	120	,10.0},
{6.79904761904756,	120	,10.0},
{6.81904761904756,	120	,10.0},
{6.83904761904756,	120	,10.0},
{6.85904761904756,	120	,10.0},
{6.87904761904756,	120	,10.0},
{6.89904761904756,	120	,10.0},
{6.91904761904756,	120	,10.0},
{6.93904761904756,	120	,10.0},
{6.95904761904756,	120	,10.0},
{6.97904761904756,	120	,10.0},
{6.99904761904756,	120	,10.0},
{7.01904761904756,	120	,10.0},
{7.03904761904756,	120	,10.0},
{7.05904761904756,	120	,10.0},
{7.07904761904756,	120	,10.0},
{7.09904761904756,	120	,10.0},
{7.11904761904756,	120	,10.0},
{7.13904761904756,	120	,10.0},
{7.15904761904755,	120	,10.0},
{7.17904761904755,	120	,10.0},
{7.19904761904755,	120	,10.0},
{7.21904761904755,	120	,10.0},
{7.23904761904755,	120	,10.0},
{7.25904761904755,	120	,10.0},
{7.27904761904755,	120	,10.0},
{7.29904761904755,	120	,10.0},
{7.31904761904755,	120	,10.0},
{7.33904761904755,	120	,10.0},
{7.35904761904755,	120	,10.0},
{7.37904761904755,	120	,10.0},
{7.39904761904755,	120	,10.0},
{7.41904761904755,	120	,10.0},
{7.43904761904755,	120	,10.0},
{7.45904761904755,	120	,10.0},
{7.47904761904755,	120	,10.0},
{7.49904761904755,	120	,10.0},
{7.51904761904755,	120	,10.0},
{7.53904761904755,	120	,10.0},
{7.55904761904755,	120	,10.0},
{7.57904761904755,	120	,10.0},
{7.59904761904755,	120	,10.0},
{7.61904761904754,	120	,10.0},
{7.63904761904754,	120	,10.0},
{7.65904761904754,	120	,10.0},
{7.67904761904754,	120	,10.0},
{7.69904761904754,	120	,10.0},
{7.71904761904754,	120	,10.0},
{7.73904761904754,	120	,10.0},
{7.75904761904754,	120	,10.0},
{7.77904761904754,	120	,10.0},
{7.79904761904754,	120	,10.0},
{7.81904761904754,	120	,10.0},
{7.83904761904754,	120	,10.0},
{7.85904761904754,	120	,10.0},
{7.87904761904754,	120	,10.0},
{7.89904761904754,	120	,10.0},
{7.91904761904754,	120	,10.0},
{7.93904761904754,	120	,10.0},
{7.95904761904754,	120	,10.0},
{7.97904761904754,	120	,10.0},
{7.99904761904754,	120	,10.0},
{8.01904761904754,	120	,10.0},
{8.03904761904754,	120	,10.0},
{8.05904761904754,	120	,10.0},
{8.07904761904754,	120	,10.0},
{8.09904761904754,	120	,10.0},
{8.11904761904754,	120	,10.0},
{8.13904761904753,	120	,10.0},
{8.15904761904753,	120	,10.0},
{8.17904761904753,	120	,10.0},
{8.19904761904753,	120	,10.0},
{8.21904761904753,	120	,10.0},
{8.23904761904753,	120	,10.0},
{8.25904761904753,	120	,10.0},
{8.27904761904753,	120	,10.0},
{8.29904761904753,	120	,10.0},
{8.31904761904753,	120	,10.0},
{8.33904761904753,	120	,10.0},
{8.35904761904753,	120	,10.0},
{8.37904761904753,	120	,10.0},
{8.39904761904753,	120	,10.0},
{8.41904761904753,	120	,10.0},
{8.43904761904753,	120	,10.0},
{8.45904761904753,	120	,10.0},
{8.47904761904753,	120	,10.0},
{8.49904761904753,	120	,10.0},
{8.51904761904753,	120	,10.0},
{8.53904761904753,	120	,10.0},
{8.55904761904753,	120	,10.0},
{8.57904761904753,	120	,10.0},
{8.59904761904752,	120	,10.0},
{8.61904761904752,	120	,10.0},
{8.63904761904752,	120	,10.0},
{8.65904761904752,	120	,10.0},
{8.67904761904752,	120	,10.0},
{8.69904761904752,	120	,10.0},
{8.71904761904752,	120	,10.0},
{8.73904761904752,	120	,10.0},
{8.75904761904752,	120	,10.0},
{8.77904761904752,	120	,10.0},
{8.79904761904752,	120	,10.0},
{8.81904761904752,	120	,10.0},
{8.83904761904752,	120	,10.0},
{8.85904761904752,	120	,10.0},
{8.87904761904752,	120	,10.0},
{8.89904761904752,	120	,10.0},
{8.91904761904752,	120	,10.0},
{8.93904761904752,	120	,10.0},
{8.95904761904752,	120	,10.0},
{8.97904761904752,	120	,10.0},
{8.99904761904752,	120	,10.0},
{9.01904761904752,	120	,10.0},
{9.03904761904752,	120	,10.0},
{9.05904761904752,	120	,10.0},
{9.07904761904751,	120	,10.0},
{9.09904761904751,	120	,10.0},
{9.11904761904751,	120	,10.0},
{9.13904761904751,	120	,10.0},
{9.15904761904751,	120	,10.0},
{9.17904761904751,	120	,10.0},
{9.19904761904751,	120	,10.0},
{9.21904761904751,	120	,10.0},
{9.23904761904751,	120	,10.0},
{9.25904761904751,	120	,10.0},
{9.27904761904751,	120	,10.0},
{9.29904761904751,	120	,10.0},
{9.31904761904751,	120	,10.0},
{9.33904761904751,	120	,10.0},
{9.35904761904751,	120	,10.0},
{9.37904761904751,	120	,10.0},
{9.39904761904751,	120	,10.0},
{9.41904761904751,	120	,10.0},
{9.4390238095237,	119.714285714286	,10.0},
{9.45894047619037,	119.285714285714	,10.0},
{9.4787738095237,	118.714285714286	,10.0},
{9.49849999999989,	118	,10.0},
{9.51809523809513,	117.142857142857	,10.0},
{9.5375357142856,	116.142857142857	,10.0},
{9.55679761904751,	115	,10.0},
{9.57585714285703,	113.714285714286	,10.0},
{9.59469047619037,	112.285714285714	,10.0},
{9.6132738095237,	110.714285714286	,10.0},
{9.63158333333322,	109	,10.0},
{9.64959523809513,	107.142857142857	,10.0},
{9.6672857142856,	105.142857142857	,10.0},
{9.68463095238084,	103	,10.0},
{9.70160714285703,	100.714285714286	,10.0},
{9.71819047619037,	98.2857142857142	,10.0},
{9.73435714285703,	95.7142857142857	,10.0},
{9.75008333333322,	93	,10.0},
{9.76534523809513,	90.1428571428571	,10.0},
{9.78011904761894,	87.1428571428571	,10.0},
{9.79439285714275,	84.1428571428571	,10.0},
{9.80816666666656,	81.1428571428571	,10.0},
{9.82144047619037,	78.1428571428571	,10.0},
{9.83421428571418,	75.1428571428571	,10.0},
{9.84648809523799,	72.1428571428571	,10.0},
{9.85826190476179,	69.1428571428571	,10.0},
{9.8695357142856,	66.1428571428571	,10.0},
{9.88030952380941,	63.1428571428571	,10.0},
{9.89058333333322,	60.1428571428571	,10.0},
{9.90035714285703,	57.1428571428571	,10.0},
{9.90963095238084,	54.1428571428571	,10.0},
{9.91840476190465,	51.1428571428571	,10.0},
{9.92667857142846,	48.1428571428571	,10.0},
{9.93445238095227,	45.1428571428571	,10.0},
{9.94172619047608,	42.1428571428571	,10.0},
{9.94849999999989,	39.1428571428571	,10.0},
{9.9547738095237,	36.1428571428571	,10.0},
{9.96054761904751,	33.1428571428571	,10.0},
{9.96582142857132,	30.1428571428571	,10.0},
{9.97059523809513,	27.1428571428571	,10.0},
{9.97489285714275,	24.4285714285714	,10.0},
{9.97874999999989,	21.8571428571428	,10.0},
{9.98219047619037,	19.4285714285714	,10.0},
{9.98523809523799,	17.1428571428571	,10.0},
{9.98791666666656,	15	,10.0},
{9.99024999999989,	13	,10.0},
{9.99226190476179,	11.1428571428571	,10.0},
{9.99397619047608,	9.42857142857139	,10.0},
{9.99541666666656,	7.85714285714282	,10.0},
{9.99660714285703,	6.4285714285714	,10.0},
{9.99757142857132,	5.14285714285711	,10.0},
{9.99833333333322,	3.99999999999998	,10.0},
{9.99891666666656,	2.99999999999998	,10.0},
{9.99934523809513,	2.14285714285713	,10.0},
{9.99964285714275,	1.42857142857142	,10.0},
{9.99983333333322,	0.857142857142847	,10.0},
{9.99994047619036,	0.428571428571422	,10.0},
{9.99998809523798,	0.142857142857139	,10.0},
{9.99999999999989,	0	,10.0}};