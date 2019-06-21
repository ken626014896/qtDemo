#include "crctool.h"

CRCTool::CRCTool(QObject *parent) : QObject(parent)
{

}

void CRCTool::AddCRC16(uint16_t *buffer, uint16_t n, uint16_t *pcrc)
{
    uint16_t i,j,carry_flag,a;

       for (i=0; i<n; i++)
       {
           *pcrc=*pcrc^buffer[i];
           for (j=0; j<8; j++)
           {
               a=*pcrc;
               carry_flag=a&0x0001;
               *pcrc=*pcrc>>1;
               if (carry_flag==1)
                   *pcrc=*pcrc^0xa001;
           }
       }

}

uint16_t CRCTool::CheckCRC16(uint8_t *buffer, uint16_t n)
{
    uint16_t crc0 = 0x0;
    uint16_t crc1 = 0xffff;

       if(n>=2)
       {
           crc0 = ((buffer[n-2]<<8)|buffer[n-1]);
//           AddCRC16(buffer,n-2,&crc1);
       }

       return (crc0==crc1);

}
