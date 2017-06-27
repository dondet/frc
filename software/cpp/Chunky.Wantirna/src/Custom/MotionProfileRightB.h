// COLUMN 1 = Position (rotations)
// COLUMN 2 = Velocity (rpm)
// COLUMN 3 = Duration (ms)
const int kRightBSz = 683;
const double kRightB[][3] = {
{0,	0	,10},
{2.38095238095238e-05,	0.285714285714286	,10},
{0.000107142857142857,	0.714285714285714	,10},
{0.000273809523809524,	1.28571428571429	,10},
{0.000547619047619048,	2	,10},
{0.000952380952380952,	2.85714285714286	,10},
{0.00151190476190476,	3.85714285714286	,10},
{0.00225,	5	,10},
{0.00319047619047619,	6.28571428571428	,10},
{0.00435714285714286,	7.71428571428572	,10},
{0.00577380952380952,	9.28571428571429	,10},
{0.00746428571428571,	11	,10},
{0.00945238095238095,	12.8571428571429	,10},
{0.0117619047619048,	14.8571428571429	,10},
{0.0144166666666667,	17	,10},
{0.0174404761904762,	19.2857142857143	,10},
{0.0208571428571429,	21.7142857142857	,10},
{0.0246904761904762,	24.2857142857143	,10},
{0.0289642857142857,	27	,10},
{0.033702380952381,	29.8571428571429	,10},
{0.0389285714285714,	32.8571428571429	,10},
{0.0446547619047619,	35.8571428571429	,10},
{0.0508809523809524,	38.8571428571429	,10},
{0.0576071428571429,	41.8571428571429	,10},
{0.0648333333333333,	44.8571428571429	,10},
{0.0725595238095238,	47.8571428571429	,10},
{0.0807857142857143,	50.8571428571429	,10},
{0.0895119047619048,	53.8571428571429	,10},
{0.0987380952380952,	56.8571428571429	,10},
{0.108464285714286,	59.8571428571429	,10},
{0.118690476190476,	62.8571428571429	,10},
{0.129416666666667,	65.8571428571429	,10},
{0.140642857142857,	68.8571428571429	,10},
{0.152369047619048,	71.8571428571429	,10},
{0.164595238095238,	74.8571428571429	,10},
{0.177321428571429,	77.8571428571429	,10},
{0.190547619047619,	80.8571428571429	,10},
{0.20427380952381,	83.8571428571429	,10},
{0.2185,	86.8571428571429	,10},
{0.23322619047619,	89.8571428571429	,10},
{0.248452380952381,	92.8571428571429	,10},
{0.264154761904762,	95.5714285714286	,10},
{0.280297619047619,	98.1428571428572	,10},
{0.296857142857143,	100.571428571429	,10},
{0.313809523809524,	102.857142857143	,10},
{0.331130952380952,	105	,10},
{0.348797619047619,	107	,10},
{0.366785714285714,	108.857142857143	,10},
{0.385071428571429,	110.571428571429	,10},
{0.403630952380952,	112.142857142857	,10},
{0.422440476190476,	113.571428571429	,10},
{0.44147619047619,	114.857142857143	,10},
{0.460714285714286,	116	,10},
{0.480130952380952,	117	,10},
{0.499702380952381,	117.857142857143	,10},
{0.519404761904762,	118.571428571429	,10},
{0.539214285714286,	119.142857142857	,10},
{0.559107142857143,	119.571428571429	,10},
{0.579059523809524,	119.857142857143	,10},
{0.599047619047619,	120	,10},
{0.619047619047619,	120	,10},
{0.639047619047619,	120	,10},
{0.659047619047619,	120	,10},
{0.679047619047619,	120	,10},
{0.699047619047619,	120	,10},
{0.719047619047619,	120	,10},
{0.739047619047619,	120	,10},
{0.759047619047619,	120	,10},
{0.779047619047619,	120	,10},
{0.799047619047619,	120	,10},
{0.819047619047619,	120	,10},
{0.839047619047619,	120	,10},
{0.859047619047619,	120	,10},
{0.879047619047619,	120	,10},
{0.899047619047619,	120	,10},
{0.919047619047619,	120	,10},
{0.939047619047619,	120	,10},
{0.959047619047619,	120	,10},
{0.979047619047619,	120	,10},
{0.999047619047619,	120	,10},
{1.01904761904762,	120	,10},
{1.03904761904762,	120	,10},
{1.05904761904762,	120	,10},
{1.07904761904762,	120	,10},
{1.09904761904762,	120	,10},
{1.11904761904762,	120	,10},
{1.13904761904762,	120	,10},
{1.15904761904762,	120	,10},
{1.17904761904762,	120	,10},
{1.19904761904762,	120	,10},
{1.21904761904762,	120	,10},
{1.23904761904762,	120	,10},
{1.25904761904762,	120	,10},
{1.27904761904762,	120	,10},
{1.29904761904762,	120	,10},
{1.31904761904762,	120	,10},
{1.33904761904762,	120	,10},
{1.35904761904762,	120	,10},
{1.37904761904762,	120	,10},
{1.39904761904762,	120	,10},
{1.41904761904762,	120	,10},
{1.43904761904762,	120	,10},
{1.45904761904762,	120	,10},
{1.47904761904762,	120	,10},
{1.49904761904762,	120	,10},
{1.51904761904762,	120	,10},
{1.53904761904762,	120	,10},
{1.55904761904762,	120	,10},
{1.57904761904762,	120	,10},
{1.59904761904762,	120	,10},
{1.61904761904762,	120	,10},
{1.63904761904762,	120	,10},
{1.65904761904762,	120	,10},
{1.67904761904762,	120	,10},
{1.69904761904762,	120	,10},
{1.71904761904762,	120	,10},
{1.73904761904762,	120	,10},
{1.75904761904762,	120	,10},
{1.77904761904762,	120	,10},
{1.79904761904762,	120	,10},
{1.81904761904762,	120	,10},
{1.83904761904762,	120	,10},
{1.85904761904762,	120	,10},
{1.87904761904762,	120	,10},
{1.89904761904762,	120	,10},
{1.91904761904762,	120	,10},
{1.93904761904762,	120	,10},
{1.95904761904762,	120	,10},
{1.97904761904762,	120	,10},
{1.99904761904762,	120	,10},
{2.01904761904762,	120	,10},
{2.03904761904762,	120	,10},
{2.05904761904762,	120	,10},
{2.07904761904762,	120	,10},
{2.09904761904762,	120	,10},
{2.11904761904762,	120	,10},
{2.13904761904762,	120	,10},
{2.15904761904762,	120	,10},
{2.17904761904762,	120	,10},
{2.19904761904762,	120	,10},
{2.21904761904762,	120	,10},
{2.23904761904762,	120	,10},
{2.25904761904762,	120	,10},
{2.27904761904762,	120	,10},
{2.29904761904762,	120	,10},
{2.31904761904762,	120	,10},
{2.33904761904762,	120	,10},
{2.35904761904762,	120	,10},
{2.37904761904762,	120	,10},
{2.39904761904762,	120	,10},
{2.41904761904762,	120	,10},
{2.43904761904762,	120	,10},
{2.45904761904762,	120	,10},
{2.47904761904762,	120	,10},
{2.49904761904762,	120	,10},
{2.51904761904762,	120	,10},
{2.53904761904762,	120	,10},
{2.55904761904762,	120	,10},
{2.57904761904762,	120	,10},
{2.59904761904762,	120	,10},
{2.61904761904762,	120	,10},
{2.63904761904762,	120	,10},
{2.65904761904762,	120	,10},
{2.67904761904762,	120	,10},
{2.69904761904762,	120	,10},
{2.71904761904762,	120	,10},
{2.73904761904762,	120	,10},
{2.75904761904762,	120	,10},
{2.77904761904762,	120	,10},
{2.79904761904762,	120	,10},
{2.81904761904762,	120	,10},
{2.83904761904762,	120	,10},
{2.85904761904762,	120	,10},
{2.87904761904762,	120	,10},
{2.89904761904762,	120	,10},
{2.91904761904762,	120	,10},
{2.93904761904762,	120	,10},
{2.95904761904762,	120	,10},
{2.97904761904762,	120	,10},
{2.99904761904762,	120	,10},
{3.01904761904762,	120	,10},
{3.03904761904762,	120	,10},
{3.05904761904762,	120	,10},
{3.07904761904762,	120	,10},
{3.09904761904762,	120	,10},
{3.11904761904762,	120	,10},
{3.13904761904762,	120	,10},
{3.15904761904762,	120	,10},
{3.17904761904762,	120	,10},
{3.19904761904762,	120	,10},
{3.21904761904762,	120	,10},
{3.23904761904762,	120	,10},
{3.25904761904762,	120	,10},
{3.27904761904762,	120	,10},
{3.29904761904762,	120	,10},
{3.31904761904762,	120	,10},
{3.33904761904762,	120	,10},
{3.35904761904762,	120	,10},
{3.37904761904762,	120	,10},
{3.39904761904762,	120	,10},
{3.41904761904762,	120	,10},
{3.43904761904762,	120	,10},
{3.45904761904762,	120	,10},
{3.47904761904762,	120	,10},
{3.49904761904762,	120	,10},
{3.51904761904762,	120	,10},
{3.53904761904762,	120	,10},
{3.55904761904762,	120	,10},
{3.57904761904762,	120	,10},
{3.59904761904762,	120	,10},
{3.61904761904762,	120	,10},
{3.63904761904762,	120	,10},
{3.65904761904762,	120	,10},
{3.67904761904762,	120	,10},
{3.69904761904762,	120	,10},
{3.71904761904762,	120	,10},
{3.73904761904762,	120	,10},
{3.75904761904762,	120	,10},
{3.77904761904762,	120	,10},
{3.79904761904762,	120	,10},
{3.81904761904762,	120	,10},
{3.83904761904762,	120	,10},
{3.85904761904762,	120	,10},
{3.87904761904762,	120	,10},
{3.89904761904762,	120	,10},
{3.91904761904762,	120	,10},
{3.93904761904762,	120	,10},
{3.95904761904762,	120	,10},
{3.97904761904762,	120	,10},
{3.99904761904762,	120	,10},
{4.01904761904762,	120	,10},
{4.03904761904762,	120	,10},
{4.05904761904762,	120	,10},
{4.07904761904762,	120	,10},
{4.09904761904762,	120	,10},
{4.11904761904762,	120	,10},
{4.13904761904762,	120	,10},
{4.15904761904762,	120	,10},
{4.17904761904762,	120	,10},
{4.19904761904762,	120	,10},
{4.21904761904762,	120	,10},
{4.23904761904762,	120	,10},
{4.25904761904762,	120	,10},
{4.27904761904762,	120	,10},
{4.29904761904762,	120	,10},
{4.31904761904762,	120	,10},
{4.33904761904761,	120	,10},
{4.35904761904761,	120	,10},
{4.37904761904761,	120	,10},
{4.39904761904761,	120	,10},
{4.41904761904761,	120	,10},
{4.43904761904761,	120	,10},
{4.45904761904761,	120	,10},
{4.47904761904761,	120	,10},
{4.49904761904761,	120	,10},
{4.51904761904761,	120	,10},
{4.53904761904761,	120	,10},
{4.55904761904761,	120	,10},
{4.57904761904761,	120	,10},
{4.59904761904761,	120	,10},
{4.61904761904761,	120	,10},
{4.63904761904761,	120	,10},
{4.65904761904761,	120	,10},
{4.67904761904761,	120	,10},
{4.69904761904761,	120	,10},
{4.71904761904761,	120	,10},
{4.73904761904761,	120	,10},
{4.75904761904761,	120	,10},
{4.77904761904761,	120	,10},
{4.79904761904761,	120	,10},
{4.8190476190476,	120	,10},
{4.8390476190476,	120	,10},
{4.8590476190476,	120	,10},
{4.8790476190476,	120	,10},
{4.8990476190476,	120	,10},
{4.9190476190476,	120	,10},
{4.9390476190476,	120	,10},
{4.9590476190476,	120	,10},
{4.9790476190476,	120	,10},
{4.9990476190476,	120	,10},
{5.0190476190476,	120	,10},
{5.0390476190476,	120	,10},
{5.0590476190476,	120	,10},
{5.0790476190476,	120	,10},
{5.0990476190476,	120	,10},
{5.1190476190476,	120	,10},
{5.1390476190476,	120	,10},
{5.1590476190476,	120	,10},
{5.1790476190476,	120	,10},
{5.1990476190476,	120	,10},
{5.2190476190476,	120	,10},
{5.2390476190476,	120	,10},
{5.2590476190476,	120	,10},
{5.27904761904759,	120	,10},
{5.29904761904759,	120	,10},
{5.31904761904759,	120	,10},
{5.33904761904759,	120	,10},
{5.35904761904759,	120	,10},
{5.37904761904759,	120	,10},
{5.39904761904759,	120	,10},
{5.41904761904759,	120	,10},
{5.43904761904759,	120	,10},
{5.45904761904759,	120	,10},
{5.47904761904759,	120	,10},
{5.49904761904759,	120	,10},
{5.51904761904759,	120	,10},
{5.53904761904759,	120	,10},
{5.55904761904759,	120	,10},
{5.57904761904759,	120	,10},
{5.59904761904759,	120	,10},
{5.61904761904759,	120	,10},
{5.63904761904759,	120	,10},
{5.65904761904759,	120	,10},
{5.67904761904759,	120	,10},
{5.69904761904759,	120	,10},
{5.71904761904759,	120	,10},
{5.73904761904758,	120	,10},
{5.75904761904758,	120	,10},
{5.77904761904758,	120	,10},
{5.79904761904758,	120	,10},
{5.81904761904758,	120	,10},
{5.83904761904758,	120	,10},
{5.85904761904758,	120	,10},
{5.87904761904758,	120	,10},
{5.89904761904758,	120	,10},
{5.91904761904758,	120	,10},
{5.93904761904758,	120	,10},
{5.95904761904758,	120	,10},
{5.97904761904758,	120	,10},
{5.99904761904758,	120	,10},
{6.01904761904758,	120	,10},
{6.03904761904758,	120	,10},
{6.05904761904758,	120	,10},
{6.07904761904758,	120	,10},
{6.09904761904758,	120	,10},
{6.11904761904758,	120	,10},
{6.13904761904758,	120	,10},
{6.15904761904758,	120	,10},
{6.17904761904758,	120	,10},
{6.19904761904758,	120	,10},
{6.21904761904757,	120	,10},
{6.23904761904757,	120	,10},
{6.25904761904757,	120	,10},
{6.27904761904757,	120	,10},
{6.29904761904757,	120	,10},
{6.31904761904757,	120	,10},
{6.33904761904757,	120	,10},
{6.35904761904757,	120	,10},
{6.37904761904757,	120	,10},
{6.39904761904757,	120	,10},
{6.41904761904757,	120	,10},
{6.43904761904757,	120	,10},
{6.45904761904757,	120	,10},
{6.47904761904757,	120	,10},
{6.49904761904757,	120	,10},
{6.51904761904757,	120	,10},
{6.53904761904757,	120	,10},
{6.55904761904757,	120	,10},
{6.57904761904757,	120	,10},
{6.59904761904757,	120	,10},
{6.61904761904757,	120	,10},
{6.63904761904757,	120	,10},
{6.65904761904757,	120	,10},
{6.67904761904756,	120	,10},
{6.69904761904756,	120	,10},
{6.71904761904756,	120	,10},
{6.73904761904756,	120	,10},
{6.75904761904756,	120	,10},
{6.77904761904756,	120	,10},
{6.79904761904756,	120	,10},
{6.81904761904756,	120	,10},
{6.83904761904756,	120	,10},
{6.85904761904756,	120	,10},
{6.87904761904756,	120	,10},
{6.89904761904756,	120	,10},
{6.91904761904756,	120	,10},
{6.93904761904756,	120	,10},
{6.95904761904756,	120	,10},
{6.97904761904756,	120	,10},
{6.99904761904756,	120	,10},
{7.01904761904756,	120	,10},
{7.03904761904756,	120	,10},
{7.05904761904756,	120	,10},
{7.07904761904756,	120	,10},
{7.09904761904756,	120	,10},
{7.11904761904756,	120	,10},
{7.13904761904756,	120	,10},
{7.15904761904755,	120	,10},
{7.17904761904755,	120	,10},
{7.19904761904755,	120	,10},
{7.21904761904755,	120	,10},
{7.23904761904755,	120	,10},
{7.25904761904755,	120	,10},
{7.27904761904755,	120	,10},
{7.29904761904755,	120	,10},
{7.31904761904755,	120	,10},
{7.33904761904755,	120	,10},
{7.35904761904755,	120	,10},
{7.37904761904755,	120	,10},
{7.39904761904755,	120	,10},
{7.41904761904755,	120	,10},
{7.43904761904755,	120	,10},
{7.45904761904755,	120	,10},
{7.47904761904755,	120	,10},
{7.49904761904755,	120	,10},
{7.51904761904755,	120	,10},
{7.53904761904755,	120	,10},
{7.55904761904755,	120	,10},
{7.57904761904755,	120	,10},
{7.59904761904755,	120	,10},
{7.61904761904754,	120	,10},
{7.63904761904754,	120	,10},
{7.65904761904754,	120	,10},
{7.67904761904754,	120	,10},
{7.69904761904754,	120	,10},
{7.71904761904754,	120	,10},
{7.73904761904754,	120	,10},
{7.75904761904754,	120	,10},
{7.77904761904754,	120	,10},
{7.79904761904754,	120	,10},
{7.81904761904754,	120	,10},
{7.83904761904754,	120	,10},
{7.85904761904754,	120	,10},
{7.87904761904754,	120	,10},
{7.89904761904754,	120	,10},
{7.91904761904754,	120	,10},
{7.93904761904754,	120	,10},
{7.95904761904754,	120	,10},
{7.97904761904754,	120	,10},
{7.99904761904754,	120	,10},
{8.01904761904754,	120	,10},
{8.03904761904754,	120	,10},
{8.05904761904754,	120	,10},
{8.07904761904754,	120	,10},
{8.09904761904754,	120	,10},
{8.11904761904754,	120	,10},
{8.13904761904753,	120	,10},
{8.15904761904753,	120	,10},
{8.17904761904753,	120	,10},
{8.19904761904753,	120	,10},
{8.21904761904753,	120	,10},
{8.23904761904753,	120	,10},
{8.25904761904753,	120	,10},
{8.27904761904753,	120	,10},
{8.29904761904753,	120	,10},
{8.31904761904753,	120	,10},
{8.33904761904753,	120	,10},
{8.35904761904753,	120	,10},
{8.37904761904753,	120	,10},
{8.39904761904753,	120	,10},
{8.41904761904753,	120	,10},
{8.43904761904753,	120	,10},
{8.45904761904753,	120	,10},
{8.47904761904753,	120	,10},
{8.49904761904753,	120	,10},
{8.51904761904753,	120	,10},
{8.53904761904753,	120	,10},
{8.55904761904753,	120	,10},
{8.57904761904753,	120	,10},
{8.59904761904752,	120	,10},
{8.61904761904752,	120	,10},
{8.63904761904752,	120	,10},
{8.65904761904752,	120	,10},
{8.67904761904752,	120	,10},
{8.69904761904752,	120	,10},
{8.71904761904752,	120	,10},
{8.73904761904752,	120	,10},
{8.75904761904752,	120	,10},
{8.77904761904752,	120	,10},
{8.79904761904752,	120	,10},
{8.81904761904752,	120	,10},
{8.83904761904752,	120	,10},
{8.85904761904752,	120	,10},
{8.87904761904752,	120	,10},
{8.89904761904752,	120	,10},
{8.91904761904752,	120	,10},
{8.93904761904752,	120	,10},
{8.95904761904752,	120	,10},
{8.97904761904752,	120	,10},
{8.99904761904752,	120	,10},
{9.01904761904752,	120	,10},
{9.03904761904752,	120	,10},
{9.05904761904752,	120	,10},
{9.07904761904751,	120	,10},
{9.09904761904751,	120	,10},
{9.11904761904751,	120	,10},
{9.13904761904751,	120	,10},
{9.15904761904751,	120	,10},
{9.17904761904751,	120	,10},
{9.19904761904751,	120	,10},
{9.21904761904751,	120	,10},
{9.23904761904751,	120	,10},
{9.25904761904751,	120	,10},
{9.27904761904751,	120	,10},
{9.29904761904751,	120	,10},
{9.31904761904751,	120	,10},
{9.33904761904751,	120	,10},
{9.35904761904751,	120	,10},
{9.37904761904751,	120	,10},
{9.39904761904751,	120	,10},
{9.41904761904751,	120	,10},
{9.43904761904751,	120	,10},
{9.45904761904751,	120	,10},
{9.47904761904751,	120	,10},
{9.49904761904751,	120	,10},
{9.51904761904751,	120	,10},
{9.5390476190475,	120	,10},
{9.5590476190475,	120	,10},
{9.5790476190475,	120	,10},
{9.5990476190475,	120	,10},
{9.6190476190475,	120	,10},
{9.6390476190475,	120	,10},
{9.6590476190475,	120	,10},
{9.6790476190475,	120	,10},
{9.6990476190475,	120	,10},
{9.7190476190475,	120	,10},
{9.7390476190475,	120	,10},
{9.7590476190475,	120	,10},
{9.7790476190475,	120	,10},
{9.7990476190475,	120	,10},
{9.8190476190475,	120	,10},
{9.8390476190475,	120	,10},
{9.8590476190475,	120	,10},
{9.8790476190475,	120	,10},
{9.8990476190475,	120	,10},
{9.9190476190475,	120	,10},
{9.9390476190475,	120	,10},
{9.9590476190475,	120	,10},
{9.9790476190475,	120	,10},
{9.9990476190475,	120	,10},
{10.0190476190475,	120	,10},
{10.0390476190475,	120	,10},
{10.0590476190475,	120	,10},
{10.0790476190475,	120	,10},
{10.0990476190475,	120	,10},
{10.1190476190475,	120	,10},
{10.1390476190475,	120	,10},
{10.1590476190475,	120	,10},
{10.1790476190475,	120	,10},
{10.1990476190475,	120	,10},
{10.2190476190475,	120	,10},
{10.2390476190475,	120	,10},
{10.2590476190475,	120	,10},
{10.2790476190475,	120	,10},
{10.2990476190475,	120	,10},
{10.3190476190475,	120	,10},
{10.3390476190475,	120	,10},
{10.3590476190475,	120	,10},
{10.3790476190475,	120	,10},
{10.3990476190475,	120	,10},
{10.4190476190475,	120	,10},
{10.4390476190475,	120	,10},
{10.4590476190475,	120	,10},
{10.4790476190475,	120	,10},
{10.4990476190475,	120	,10},
{10.5190476190475,	120	,10},
{10.5390476190475,	120	,10},
{10.5590476190475,	120	,10},
{10.5790476190475,	120	,10},
{10.5990476190475,	120	,10},
{10.6190476190475,	120	,10},
{10.6390476190475,	120	,10},
{10.6590476190475,	120	,10},
{10.6790476190475,	120	,10},
{10.6990476190475,	120	,10},
{10.7190476190475,	120	,10},
{10.7390476190475,	120	,10},
{10.7590476190475,	120	,10},
{10.7790476190475,	120	,10},
{10.7990476190475,	120	,10},
{10.8190476190475,	120	,10},
{10.8390476190475,	120	,10},
{10.8590476190475,	120	,10},
{10.8790476190475,	120	,10},
{10.8990476190475,	120	,10},
{10.9190476190475,	120	,10},
{10.9390476190475,	120	,10},
{10.9590476190475,	120	,10},
{10.9790476190475,	120	,10},
{10.9990476190475,	120	,10},
{11.0190476190475,	120	,10},
{11.0390476190475,	120	,10},
{11.0590476190475,	120	,10},
{11.0790476190475,	120	,10},
{11.0990476190475,	120	,10},
{11.1190476190475,	120	,10},
{11.1390476190475,	120	,10},
{11.1590476190475,	120	,10},
{11.1790476190475,	120	,10},
{11.1990476190475,	120	,10},
{11.2190476190475,	120	,10},
{11.2390476190475,	120	,10},
{11.2590476190475,	120	,10},
{11.2790476190475,	120	,10},
{11.2990476190475,	120	,10},
{11.3190476190475,	120	,10},
{11.3390476190475,	120	,10},
{11.3590476190475,	120	,10},
{11.3790476190475,	120	,10},
{11.3990476190475,	120	,10},
{11.4190476190475,	120	,10},
{11.4390476190475,	120	,10},
{11.4590476190475,	120	,10},
{11.4790476190475,	120	,10},
{11.4990476190475,	120	,10},
{11.5190476190475,	120	,10},
{11.5390476190475,	120	,10},
{11.5590476190475,	120	,10},
{11.5790476190475,	120	,10},
{11.5990476190475,	120	,10},
{11.6190476190475,	120	,10},
{11.6390476190475,	120	,10},
{11.6590476190475,	120	,10},
{11.6790476190475,	120	,10},
{11.6990476190475,	120	,10},
{11.7190476190475,	120	,10},
{11.7390476190475,	120	,10},
{11.7590476190475,	120	,10},
{11.7790476190475,	120	,10},
{11.7990476190475,	120	,10},
{11.8190476190475,	120	,10},
{11.8390476190475,	120	,10},
{11.8590476190475,	120	,10},
{11.8790476190475,	120	,10},
{11.8990238095236,	119.714285714286	,10},
{11.9189404761903,	119.285714285714	,10},
{11.9387738095236,	118.714285714286	,10},
{11.9584999999998,	118	,10},
{11.9780952380951,	117.142857142857	,10},
{11.9975357142856,	116.142857142857	,10},
{12.0167976190475,	115	,10},
{12.035857142857,	113.714285714286	,10},
{12.0546904761903,	112.285714285714	,10},
{12.0732738095236,	110.714285714286	,10},
{12.0915833333332,	109	,10},
{12.1095952380951,	107.142857142857	,10},
{12.1272857142856,	105.142857142857	,10},
{12.1446309523808,	103	,10},
{12.161607142857,	100.714285714286	,10},
{12.1781904761903,	98.2857142857142	,10},
{12.194357142857,	95.7142857142857	,10},
{12.2100833333332,	93	,10},
{12.2253452380951,	90.1428571428571	,10},
{12.2401190476189,	87.1428571428571	,10},
{12.2543928571427,	84.1428571428571	,10},
{12.2681666666665,	81.1428571428571	,10},
{12.2814404761903,	78.1428571428571	,10},
{12.2942142857141,	75.1428571428571	,10},
{12.3064880952379,	72.1428571428571	,10},
{12.3182619047617,	69.1428571428571	,10},
{12.3295357142856,	66.1428571428571	,10},
{12.3403095238094,	63.1428571428571	,10},
{12.3505833333332,	60.1428571428571	,10},
{12.360357142857,	57.1428571428571	,10},
{12.3696309523808,	54.1428571428571	,10},
{12.3784047619046,	51.1428571428571	,10},
{12.3866785714284,	48.1428571428571	,10},
{12.3944523809522,	45.1428571428571	,10},
{12.401726190476,	42.1428571428571	,10},
{12.4084999999998,	39.1428571428571	,10},
{12.4147738095236,	36.1428571428571	,10},
{12.4205476190475,	33.1428571428571	,10},
{12.4258214285713,	30.1428571428571	,10},
{12.4305952380951,	27.1428571428571	,10},
{12.4348928571427,	24.4285714285714	,10},
{12.4387499999998,	21.8571428571428	,10},
{12.4421904761903,	19.4285714285714	,10},
{12.4452380952379,	17.1428571428571	,10},
{12.4479166666665,	15	,10},
{12.4502499999998,	13	,10},
{12.4522619047617,	11.1428571428571	,10},
{12.453976190476,	9.42857142857139	,10},
{12.4554166666665,	7.85714285714282	,10},
{12.456607142857,	6.4285714285714	,10},
{12.4575714285713,	5.14285714285711	,10},
{12.4583333333332,	3.99999999999998	,10},
{12.4589166666665,	2.99999999999998	,10},
{12.4593452380951,	2.14285714285713	,10},
{12.4596428571427,	1.42857142857142	,10},
{12.4598333333332,	0.857142857142847	,10},
{12.4599404761903,	0.428571428571422	,10},
{12.4599880952379,	0.142857142857139	,10},
{12.4599999999998,	0	,10}};
