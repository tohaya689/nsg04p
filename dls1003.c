/*****************************************************************************/
/*   SYSTEM        NAME      :      DELTA 汎用抽出ﾂｰﾙ                        */
/*   SUBSYSTEM     NAME      :      抽出ﾌﾟﾛｾｽ                                */
/*   PROGRAM       NAME      :      ファイルＰＵＲＧＥ ＤＡＴＡ　            */
/*   SOURCE FILE   NAME      :      DLS1003                                  */
/*   SPACER        NAME      :      VIC TOKAI                                */
/*                 DATE      :                                               */
/*   CODER         NAME      :      VIC TOKAI                                */
/*                 DATE      :      1998.07.03                               */
/*                           :                                               */
/*   FUNCTION                :      ファイルのＰＵＲＧＥＤＡＴＡをする。     */
/*                           :                                               */
/*                           :                                               */
/*   MODIFY        LOG                                                       */
/*    NO    DATE      CODER           DESCRIPTION                            */
/*    ----  --------  --------------  -------------------------------        */
/*     01   99/01/14  NTS M.Fukunaga  ﾗｰｼﾞﾒﾓﾘｰへ変更                         */
/*                                    " #01 99/01/14 "    　　               */
/*     02   00/10/25  NTS T.Fukuanag  BigFile対応　不具合対応(purgedata指定) */
/*                                    " #02 00/10/25                         */
/*     03   07/07/12  VIC CHEN        コンパイルウオーニング対応             */
/*                                    " #03 07/07/12 "                       */
/*    ----  --------  --------------  -------------------------------        */
/*****************************************************************************/
/*** コンパイルオプション ***/
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

/***    固 定 値 定 義    ***/
#define  WRITEONLY    2
#define  EXCLUSIVE    1
#define  PURGEDATA   20

/*** インクルードファイル ***/
#include  <stdioh>    nolist
#include  <stdlibh>   nolist
#include  <stringh>   nolist
#include  <talh>      nolist
#include  <cextdecs>  nolist

/***   関数プロトタイプ   ***/
short  dls1003_file_purgedata(char *, short);

/*****************************************************************************/
/*                                                                           */
/*       関数名：ファイルＰＵＲＧＥ　ＤＡＴＡ                                */
/*       関数ID：dls1003_file_purgedata                                      */
/*       引　数：ファイル名　　　　　　(char型ポインタ)                      */
/*               ファイル名長　　　　　(short型)                             */
/*       戻り値：0     ；正常終了                                            */
/*               0001～；ファイルＣＬＯＳＥ異常終了                          */
/*               1001～；ファイルＯＰＥＮ異常終了                            */
/*               2001～；ファイルＰＵＲＧＥＤＡＴＡ異常終了                  */
/*       概　要：指定されたファイルの内容を消去する。                        */
/*                                                                           */
/*       2019/06/14  NSGIT日本語対応　確認テスト                             */
/*       2019/06/18  追加コメント                                            */
/*       2019/06/18  追加コメント２                                          */
/*       2019/06/18  こめんと追加３                                          */
/*****************************************************************************/
short  dls1003_file_purgedata(char *filename, short filename_length) {

  short  filenum;    /* ファイルナンバー */
  short  rc;         /* リターンコード   */

  /* 対象ファイルＯＰＥＮ */
/* #02 00/10/25 Mod start */
#ifdef LARGEFILE
  rc = FILE_OPEN_(filename, filename_length, &filenum,
                  WRITEONLY, EXCLUSIVE,,,,,,,1);
#else
  rc = FILE_OPEN_(filename, filename_length, &filenum, WRITEONLY, EXCLUSIVE);
#endif
/* #02 00/10/25 Mod end   */

  if (rc != 0)  return(rc + 1000); /* ファイルオープンエラー */
  /* ファイル内容の削除 */
/****** #03 07/07/12 START ******/
  rc = (short)CONTROL(filenum, PURGEDATA);
  if (_status_eq(rc)) {  /* リターンコードのチェック */
/****** #03 07/07/12 END ******/
    FILE_CLOSE_(filenum);
    return(rc + 2000);  /* ファイル削除エラー */
  }
  /* 対象ファイルのＣＬＯＳＥ */
  return(FILE_CLOSE_(filenum));
}
/*****************************************************************************/
/*   SYSTEM        NAME      :      DELTA 汎用抽出ﾂｰﾙ                        */
/*   SUBSYSTEM     NAME      :      抽出ﾌﾟﾛｾｽ                                */
/*   PROGRAM       NAME      :      ファイルＰＵＲＧＥ ＤＡＴＡ　            */
/*   SOURCE FILE   NAME      :      DLS1003                                  */
/*****************************************************************************/
