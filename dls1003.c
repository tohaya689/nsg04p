/*****************************************************************************/
/*   SYSTEM        NAME      :      DELTA �ėp���o°�                        */
/*   SUBSYSTEM     NAME      :      ���o��۾�                                */
/*   PROGRAM       NAME      :      �t�@�C���o�t�q�f�d �c�`�s�`�@            */
/*   SOURCE FILE   NAME      :      DLS1003                                  */
/*   SPACER        NAME      :      VIC TOKAI                                */
/*                 DATE      :                                               */
/*   CODER         NAME      :      VIC TOKAI                                */
/*                 DATE      :      1998.07.03                               */
/*                           :                                               */
/*   FUNCTION                :      �t�@�C���̂o�t�q�f�d�c�`�s�`������B     */
/*                           :                                               */
/*                           :                                               */
/*   MODIFY        LOG                                                       */
/*    NO    DATE      CODER           DESCRIPTION                            */
/*    ----  --------  --------------  -------------------------------        */
/*     01   99/01/14  NTS M.Fukunaga  װ����ذ�֕ύX                         */
/*                                    " #01 99/01/14 "    �@�@               */
/*     02   00/10/25  NTS T.Fukuanag  BigFile�Ή��@�s��Ή�(purgedata�w��) */
/*                                    " #02 00/10/25                         */
/*     03   07/07/12  VIC CHEN        �R���p�C���E�I�[�j���O�Ή�             */
/*                                    " #03 07/07/12 "                       */
/*    ----  --------  --------------  -------------------------------        */
/*****************************************************************************/
/*** �R���p�C���I�v�V���� ***/
/****** #01 99/01/14 START ******/
/****** #03 07/07/12 START ******/
/*#pragma XMEM*/
/****** #03 07/07/12 END ******/
#pragma WIDE
/****** #01 99/01/14 END   ******/
/*** for Debug ***/
/****** #03 07/07/12 START ******/
/*#pragma  inspect
#pragma  symbols*/
/****** #03 07/07/12 END ******/

/***    �� �� �l �� �`    ***/
#define  WRITEONLY    2
#define  EXCLUSIVE    1
#define  PURGEDATA   20

/*** �C���N���[�h�t�@�C�� ***/
#include  <stdioh>    nolist
#include  <stdlibh>   nolist
#include  <stringh>   nolist
#include  <talh>      nolist
#include  <cextdecs>  nolist

/***   �֐��v���g�^�C�v   ***/
short  dls1003_file_purgedata(char *, short);

/*****************************************************************************/
/*                                                                           */
/*       �֐����F�t�@�C���o�t�q�f�d�@�c�`�s�`                                */
/*       �֐�ID�Fdls1003_file_purgedata                                      */
/*       ���@���F�t�@�C�����@�@�@�@�@�@(char�^�|�C���^)                      */
/*               �t�@�C�������@�@�@�@�@(short�^)                             */
/*       �߂�l�F0     �G����I��                                            */
/*               0001�`�G�t�@�C���b�k�n�r�d�ُ�I��                          */
/*               1001�`�G�t�@�C���n�o�d�m�ُ�I��                            */
/*               2001�`�G�t�@�C���o�t�q�f�d�c�`�s�`�ُ�I��                  */
/*       �T�@�v�F�w�肳�ꂽ�t�@�C���̓��e����������B                        */
/*                                                                           */
/*       2019/06/14  NSGIT���{��Ή��@�m�F�e�X�g                             */
/*       2019/06/18  �ǉ��R�����g                                            */
/*       2019/06/18  �ǉ��R�����g�Q                                          */
/*       2019/06/18  ���߂�ƒǉ��R                                          */
/*****************************************************************************/
short  dls1003_file_purgedata(char *filename, short filename_length) {

  short  filenum;    /* �t�@�C���i���o�[ */
  short  rc;         /* ���^�[���R�[�h   */

  /* �Ώۃt�@�C���n�o�d�m */
/* #02 00/10/25 Mod start */
#ifdef LARGEFILE
  rc = FILE_OPEN_(filename, filename_length, &filenum,
                  WRITEONLY, EXCLUSIVE,,,,,,,1);
#else
  rc = FILE_OPEN_(filename, filename_length, &filenum, WRITEONLY, EXCLUSIVE);
#endif
/* #02 00/10/25 Mod end   */

  if (rc != 0)  return(rc + 1000); /* �t�@�C���I�[�v���G���[ */
  /* �t�@�C�����e�̍폜 */
/****** #03 07/07/12 START ******/
  rc = (short)CONTROL(filenum, PURGEDATA);
  if (_status_eq(rc)) {  /* ���^�[���R�[�h�̃`�F�b�N */
/****** #03 07/07/12 END ******/
    FILE_CLOSE_(filenum);
    return(rc + 2000);  /* �t�@�C���폜�G���[ */
  }
  /* �Ώۃt�@�C���̂b�k�n�r�d */
  return(FILE_CLOSE_(filenum));
}
/*****************************************************************************/
/*   SYSTEM        NAME      :      DELTA �ėp���o°�                        */
/*   SUBSYSTEM     NAME      :      ���o��۾�                                */
/*   PROGRAM       NAME      :      �t�@�C���o�t�q�f�d �c�`�s�`�@            */
/*   SOURCE FILE   NAME      :      DLS1003                                  */
/*****************************************************************************/
