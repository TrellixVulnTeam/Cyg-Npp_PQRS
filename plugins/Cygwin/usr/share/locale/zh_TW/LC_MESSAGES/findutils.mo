��    ,      |  ;   �      �  )   �  �   �     |  $   �  "   �     �     �  )     *   >     i  !   z     �  7   �  �   �  �   �  [   1  q   �     �          "     '  !   .     P     e     �     �     �  P   �  )   	     I	     h	  %   �	      �	  �   �	  	  �
  6   �     �  )  �  W   	  I  a  q   �  >     "   \  |    0   �  �   -     �     �  !   �     
     %  +   @  .   l     �  "   �     �  0   �  �     ~   �  `   k  s   �     @     M     Y     ]  $   a     �     �  1   �  &   �       8   (  )   a  !   �     �     �     �  �       �  )   �     '  1  +  s   ]  @  �  e     @   x  C   �                                                  #             "   $       )   +                      &                  ,   !   
              	         (                    *         '   %                   
Report bugs to <bug-findutils@gnu.org>.
 
default path is the current directory; default expression is -print
expression may consist of: operators, options, tests, and actions:
 %s terminated by signal %d %s: exited with status 255; aborting %s: invalid number for -%c option
 %s: stopped by signal %d %s: terminated by signal %d %s: value for -%c option should be < %ld
 %s: value for -%c option should be >= %ld
 < %s ... %s > ?  Database %s is in the %s format.
 Features enabled:  Only one instance of {} is supported with -exec%s ... + Report (and track progress on fixing) bugs via the findutils bug-reporting
page at http://savannah.gnu.org/ or, if you have no web access, by sending
email to <bug-findutils@gnu.org>. The environment variable FIND_BLOCK_SIZE is not supported, the only thing that affects the block size is the POSIXLY_CORRECT environment variable Usage: %s [--version | --help]
or     %s most_common_bigrams < file-list > locate-database
 You may not use {} within the utility name for -execdir and -okdir, because this is a potential security problem. argument line too long cannot fork days double environment is too large for exec error waiting for %s error waiting for child process invalid -size type `%c' invalid argument `%s' to `%s' invalid expression invalid expression; I was expecting to find a ')' somewhere but did not see one. invalid expression; you have too many ')' invalid null argument to -size missing argument to `%s' oops -- invalid expression type (%d)! oops -- invalid expression type! operators (decreasing precedence; -and is implicit where no others are given):
      ( EXPR )   ! EXPR   -not EXPR   EXPR1 -a EXPR2   EXPR1 -and EXPR2
      EXPR1 -o EXPR2   EXPR1 -or EXPR2   EXPR1 , EXPR2
 positional options (always true): -daystart -follow -regextype

normal options (always true, specified before other expressions):
      -depth --help -maxdepth LEVELS -mindepth LEVELS -mount -noleaf
      --version -xdev -ignore_readdir_race -noignore_readdir_race
 sanity check of the fnmatch() library function failed. single tests (N can be +N or -N or N): -amin N -anewer FILE -atime N -cmin N
      -cnewer FILE -ctime N -empty -false -fstype TYPE -gid N -group NAME
      -ilname PATTERN -iname PATTERN -inum N -iwholename PATTERN -iregex PATTERN
      -links N -lname PATTERN -mmin N -mtime N -name PATTERN -newer FILE unmatched %s quote; by default quotes are special to xargs unless you use the -0 option warning: Unix filenames usually don't contain slashes (though pathnames do).  That means that '%s %s' will probably evaluate to false all the time on this system.  You might find the '-wholename' test more useful, or perhaps '-samefile'.  Alternatively, if you are using GNU grep, you could use 'find ... -print0 | grep -FzZ %s'. warning: the -d option is deprecated; please use -depth instead, because the latter is a POSIX-compliant feature. warning: the locate database can only be read from stdin once. warning: unrecognized escape `\%c' Project-Id-Version: findutils 4.2.26
Report-Msgid-Bugs-To: bug-findutils@gnu.org
POT-Creation-Date: 2013-09-22 22:13+0100
PO-Revision-Date: 2005-12-06 11:30+0800
Last-Translator: Abel Cheung <abelcheung@gmail.com>
Language-Team: Chinese (traditional) <zh-l10n@linux.org.tw>
Language: zh_TW
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
 
請向 <bug-findutils@gnu.org> 報告錯誤。
 
預設路徑為目前的目錄，預設的表達式是 -print
表達式可以包括運算子、選項、測試和操作模式：
 %s 因訊號 %d 而終止 %s: 回傳碼為 255；中止 %s: -%c 選項後的數值無效
 %s: 因訊號 %d 而停止 %s: 因訊號 %d 而中止 %s: -%c 選項後的數值必須小於 %ld
 %s: -%c 選項後的數值必須不小於 %ld
 < %s ... %s > ?  資料庫 %s 使用了%s格式。
 啟用了的功能： 在 -exec%s ... + 裡面只可以使用一次 {} 請在 http://savannah.gnu.org/ 有關錯誤報告的網頁中匯報錯誤 (或者跟進
問題修正的進度)。又或者如果您無法瀏覽網頁，可以選擇用電子郵件寄至
<bug-findutils@gnu.org>。 環境變數 FIND_BLOCK_SIZE 已經不再支援，唯一一個能夠影響檔案區段大小的環境變數是 POSIXLY_CORRECT 用法: %s [--version | --help]
或     %s most_common_bigrams < 檔案清單 > locate資料庫
 您不應該在 -execdir 和 -okdir 中使用 {} 作為程式名稱，因為這樣做可能會造成安全漏洞。 參數太長 fork 失敗 日 雙 執行 exec 時的環境變數太大 等待 %s 時出現錯誤 等待子進程時出現錯誤 -size 指定的檔案大小單位 ‘%c’ 無效 ‘%2$s’ 的參數 ‘%1$s’ 無效 表達式無效 表達式無效；‘)’ 本應出現但實際上沒有 表達式無效；出現太多的 ‘)’ -size 後是無效的空白參數 ‘%s’ 後缺少了參數 表達式類型 (%d) 無效！ 表達式類型無效！ 以下的運算子優先次序由高至低排列；如果沒有運算子，則會假設為 -and :
      ( EXPR )   ! EXPR   -not EXPR   EXPR1 -a EXPR2   EXPR1 -and EXPR2
      EXPR1 -o EXPR2   EXPR1 -or EXPR2   EXPR1 , EXPR2
 位置選項 (邏輯值永遠為 true): -daystart -follow -regextype

一般選項 (邏輯值永遠為 true，必須加在其它表達式之前):
      -depth --help -maxdepth LEVELS -mindepth LEVELS -mount -noleaf
      --version -xdev -ignore_readdir_race -noignore_readdir_race
 測試 fnmatch() 是否可用時出錯。 單 測試 (N 可以有或沒有正負號): -amin N -anewer FILE -atime N -cmin N
      -cnewer FILE -ctime N -empty -false -fstype TYPE -gid N -group NAME
      -ilname PATTERN -iname PATTERN -inum N -iwholename PATTERN -iregex PATTERN
      -links N -lname PATTERN -mmin N -mtime N -name PATTERN -newer FILE %s引號不配合；除非使用 -0 選項，否則在預設模式下引號對於 xargs 來說是有特別意義的 警告：Unix 檔案名稱中一般上不會出現斜號 (雖然完整路徑會用斜號)。即是說，在本系統中 ‘%s %s’ 可能永遠是 false。在這情況下 ‘-wholename’ 或 ‘-samefile’可能會有用。又或者，如果您使用 GNU grep，可以嘗試使用 'find ... -print0 | grep -FzZ %s'。 警告：-d 選項已經過時，請改用 -depth，因為後者才是符合 POSIX 標準的選項。 警告：locate 資料庫只可以由標準輸入讀取一次。 警告：無效辨認轉義控制序列 (escape sequence) ‘\%c’ 