#ifndef PUBLIC_FUNC_H
#define PUBLIC_FUNC_H

#include "inttype.h"
#include <iostream>
#include <vector>
#include "Mp4_root_box.h"
#include "Public_class.h"

//��ȡһ��moov���м���track
int get_track_size_in_moov(CMp4_root_box& box);
//�ҵ�moov�е�����"audio"������Ƶ("video")��
int get_track_id_by_name(CMp4_root_box& box, std::string name );
int get_video_info_in_moov(CMp4_root_box& box, CMp4_avcC_box& videoInfo);
int get_audio_info_in_moov(CMp4_root_box& box, CMp4_mp4a_box& audioInfo);

uint32_t get_sample_num_in_cur_chunk(const CMp4_stsc_box & box,	const uint32_t chunk_index);//��õ�ǰchunk�е�sample��

uint32_t get_sample_index(const CMp4_stsc_box &box,	const uint32_t chunk_index);//��õ�ǰchunk�еĵ�һ��sample��

uint32_t get_sample_size(CMp4_stsz_box &box,const uint32_t chunk_index);//���sample�Ĵ�С

// ��ȡstts��ĳ��sample��ʱ��(ӳ����һ֡������ʱ��)
uint32_t get_sample_time(CMp4_stts_box& box, const uint32_t sample_index);

int floatToInt(float f);//floatתint����������

vector<t_time> videoTime_To_soundTime(vector<t_time> vc_time, 
	vector<varible> sample_key,CMp4_root_box root );//videotimeתsoundtime

vector<uint32_t> soun_trak_find_sample( vector<CMp4_trak_box>::iterator t, 
	float timeFrom, float timeTo,int num,CMp4_root_box root);//soun����ʱ����Ӧ��sample

vector<uint32_t> video_trak_find_sample(vector<CMp4_trak_box>::iterator t,
	float timeFrom,float timeTo,int num,CMp4_root_box root);//trak����ʱ����Ӧ��sample

vector<t_time> videoTime_To_soundTime_segment( vector<t_time> vc_time, 
	vector<varible> sample_key,CMp4_root_box root );//����Ƭ��ʱ��videotimeתsountime 

int process_cut_chunk_data( FILE * fin, FILE * fout, int chunk_index,
	uint32_t chunkfrom, uint32_t sync_chunkTo,uint32_t sampleFrom, 
	uint32_t sync_to_chunk_offset, uint32_t sync_to,int num,CMp4_root_box root );	//������Ҫɾ����chunk����


void copy_chunk_data(FILE *fin,
	const uint32_t chunk_index,  //[0, end) ��ʶΪ�ڼ���Chunk
	FILE *fout,  
	int num,
	CMp4_root_box root
	);


void copy_sample_data(FILE *fin,
	const uint32_t chunk_index,  //[0, end)
	std::string name, 
	int num,CMp4_root_box root, 
	int& nSampleId);					//����һ��chunk������
	

void Error_corr( CMp4_root_box root, vector<t_time> ch_time, vector<t_time> vc_time1, vector<varible> skv, vector<varible> skcv, vector<varible> skcov, 
	vector<varible> &sample_key_video, vector<varible> &sample_key_chunk_video, vector<varible> &sync_chunk_offset_video, int i ) ;
#endif