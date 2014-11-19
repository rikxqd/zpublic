/*************************************************************************
*                                                                       *
*  I|*j^3Cl|a   "+!*%                  qt          Nd   gW              *
*  l]{y+l?MM*  !#Wla\NNP               NW          MM   I|              *
*        PW    ?E|    tWg              Wg  sC!     AW           ~@v~    *
*       NC     ?M!    yN|  WW     MK   MW@K1Y%M@   RM   #Q    QP@tim    *
*     CM|      |WQCljAE|   MD     Mg   RN     cM~  NM   WQ   MQ         *
*    #M        aQ?         MW     M3   Mg      Q(  HQ   YR  IM|         *
*   Dq         {Ql         MH    iMX   Mg     MM   QP   QM   Eg         *
* !EWNaPRag2$  +M"          $WNaHaN%   MQE$%EXW    QQ   CM    %M%a$D    *
*                                                                       *
*               Website: https://github.com/zpublic/zpublic             *
*                                                                       *
************************************************************************/

/**
* @file
* @brief �ļ�ͼ�����
*/


#pragma once
#include <atlstr.h>

namespace zl
{
namespace WinUtils
{

/**
 * @brief �ַ���ת��
 */
class ZLStrConv
{
public:
    /**
     * @brief ���ַ���ת��
     * @param[in] lpBuf      ��Ҫת�Ƶ��ַ���
     * @param[in] uCodePage  Code Page
     * @param[in] nBufLen    �ַ�������,����ַ�����0��β,��˲�������-1
     * @return ����ת������ַ���,Ϊ���ַ���ʱת��ʧ��.
     */
    static CStringW ZLA2W(LPCSTR  lpBuf, UINT uCodePage = CP_ACP, int nBufLen = -1);
    static CStringA ZLW2A(LPCWSTR lpBuf, UINT uCodePage = CP_ACP, int nBufLen = -1);
    
    /**
     * @brief ���Ⱥܴ���ַ���ת��,���ļ�����
     * @param[in] lpSrc      ��Ҫת�Ƶ��ַ���
     * @param[in] nSrcLen    �ַ�������
     * @param[in] lpDstW     ���ڴ洢ת������ַ����Ļ�����ָ��,ΪNULLʱ,��������ʵ����Ҫ�Ļ���������
     * @param[in] nDstLen    ����������
     * @param[in] uCodePage  Code Page
     * @return �ɹ�����ʵ��ת������,С�ڵ���0ʱʧ��.
     * @see MultiByteToWideChar,WideCharToMultiByte
     */
    static int ZLA2W(LPCSTR  lpSrcA, int nSrcLen, LPWSTR lpDstW, int nDstLen, UINT uCodePage = CP_ACP);
    static int ZLW2A(LPCWSTR lpSrcW, int nSrcLen, LPSTR  lpDstA, int nDstLen, UINT uCodePage = CP_ACP);
};


// ������ʵ�ֲ���

inline CStringW ZLStrConv::ZLA2W( LPCSTR lpBuf, UINT uCodePage, int nBufLen )
{
    CStringW sRetW;
    int nDstLen = ::MultiByteToWideChar( uCodePage, 0, lpBuf, nBufLen, NULL, 0 );
    if (nDstLen > 0)
    {
        wchar_t* pResult = new wchar_t[nDstLen];
        BOOL bSuc = (0 < ::MultiByteToWideChar(uCodePage, 0, lpBuf, nBufLen, pResult, nDstLen));
        if (bSuc)
        {
            sRetW.Append(pResult, nDstLen);
        }
        delete[] pResult;
    }
    return sRetW;
}

inline CStringA ZLStrConv::ZLW2A( LPCWSTR lpBuf, UINT uCodePage, int nBufLen )
{
    CStringA sRetA;
    int nDstLen = ::WideCharToMultiByte( uCodePage, 0, lpBuf, nBufLen, NULL, 0, NULL, NULL );
    if (nDstLen > 0)
    {
        char* pResult = new char[nDstLen];
        BOOL bSuc = (0 < ::WideCharToMultiByte( uCodePage, 0, lpBuf, nBufLen, pResult, nDstLen, NULL, NULL ));
        if (bSuc)
        {
            sRetA.Append(pResult, nDstLen);
        }
        delete[] pResult;
    }
    return sRetA;
}

inline int ZLStrConv::ZLA2W( LPCSTR lpSrcA, int nSrcLen, LPWSTR lpDstW, int nDstLen, UINT uCodePage )
{
    return ::MultiByteToWideChar(uCodePage, 0, lpSrcA, nSrcLen, lpDstW, nDstLen);
}

inline int ZLStrConv::ZLW2A( LPCWSTR lpSrcW, int nSrcLen, LPSTR lpDstA, int nDstLen, UINT uCodePage )
{
    return ::WideCharToMultiByte(uCodePage, 0, lpSrcW, nSrcLen, lpDstA, nDstLen, NULL, NULL);
}

}
}