/**
 * Ҷ����
 * QQȺ121376426
 * http://blog.yundiantech.com/
 */

#ifndef PCMVOLUMECONTROL_H
#define PCMVOLUMECONTROL_H

class PcmVolumeControl
{
public:
    PcmVolumeControl();

    ///bufΪ��Ҫ������������Ƶ���ݿ��׵�ַָ�룬sizeΪ���ȣ�uRepeatΪ�ظ�������ͨ����Ϊ1��volΪ���汶��,����С��1
    static void RaiseVolume(char* buf, int size, int uRepeat, double vol);

};




#endif // PCMVOLUMECONTROL_H
