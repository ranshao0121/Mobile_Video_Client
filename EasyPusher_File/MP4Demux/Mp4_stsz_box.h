#pragma once
#include "Base_box.h"
#include "inttype.h"
#include <iostream>
class CMp4_stsz_box
{
public:
	CMp4_stsz_box(void);
	~CMp4_stsz_box(void);
	CMp4_stsz_box mp4_read_stsz_box(FILE *f, int size);

	MP4_FULL_BOX;
	uint32_t samples_size_intotal;// ȫ��sample����Ŀ��������е�sample����ͬ�ĳ��ȣ�����ֶξ������ֵ��
	// ��������ֶε�ֵ����0����Щ���ȴ���sample size����
	uint32_t table_size;  
	uint32_t *sample_size_table;
};

