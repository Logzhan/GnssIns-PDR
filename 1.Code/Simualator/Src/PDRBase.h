#ifndef  _PDR_BASE_H_
#define  _PDR_BASE_H_

#include <stdint.h>

#define ACCURACY_ERR_MAX                    1000                 // GPS��accuracy���ֵ,һ�����ڳ�ʼ����
#define N                                   4                    // ����ά��
#define MAX_NO_GPS_PREDICT                  10		             // ��GPS��Ϣ״̬�����λ����������	
#define IMU_SENSOR_AXIS                     3                    // IMU������������������Ĭ��3

// �û��˶�ʶ��
#define DETECTOR_TYPE_STATIC                0                    // �û���ֹ 
#define DETECTOR_TYPE_IRREGULAR             1                    // �޹����˶�
#define DETECTOR_TYPE_HANDHELD              2                    // �ֳ��˶�
#define DETECTOR_TYPE_SWINGING              3                    // �����˶�
#define DETECTOR_NO_ERROR                   0

#define PDR_TRUE                            1
#define PDR_FALSE                           0

typedef struct {
	double xk[N];             // ϵͳ״̬����  xk[0]: ����x  xk[1]������y  xk[2]������  xk[3] �������
	double p_xk[N];           // ���Ԥ�����  xk[0]: ����x  xk[1]������y  xk[2]������  xk[3] �������
	double zk[N];
	double p_pk[N][N];
	double pk[N][N];
	double phi[N][N];
	double hk[N][N];
	double q[N][N];           // �������˲���Q����(��������)
	double r[N][N];           // �������˲�R����(�۲�����)
	double Kk[N][N];
	double lambda;
	double plat;
	double plon;
	double initHeading;
}EKFPara_t;

typedef struct Sensor {
	unsigned char update;
	int type;
	double time;
	float s[IMU_SENSOR_AXIS];
}Sensor_t;

typedef struct IMU {
	Sensor_t acc;
	Sensor_t gyr;
	Sensor_t mag;
}IMU_t;

// �û��˶����ͷ�����
typedef struct DETECTOR {
	uint32_t type;                              // �û��˶���� �� 0:��ֹ�˶� 1���޹����˶� 2���ֳ��˶� 3�������˶�
	uint32_t lastType;
	uint64_t tick;                              // ����ͳ�ƣ����ڵ������������Ƶ��
} DETECTOR_t;


typedef struct PDR {
	uint32_t        Status;                     // PDR��ǰ״̬
	uint32_t        MotionType;                 // �û��˶�����
	// �ٶ����
	double          GnssSpeed;                  // GNSS�ٶ�
	double          Heading;                    // ����
	// �������
	uint64_t        Steps;                      // ��ǰ������Ϣ
	uint64_t        LastSteps;                  // ��һ�εĲ���
} PDR_t;

#endif // ! _PDR_BASE_H