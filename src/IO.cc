#include <FGCore/IO.h>

#ifndef FGCORE_FILE_SYSTEM
#define FGCORE_FILE_SYSTEM 1

#include <FGCore/Config.h>
#include <FGCore/Macros.h>
#include <FGCore/Types.h>
#include <FGCore/String.h>
#include <ostream>

#if FG_TARGET_PLATFORM == FG_TARGET_WIN
	
#else
#	include <dirent.h>  
#	include <stdlib.h>  
#	include <sys/types.h>  
#	include <sys/stat.h>  
#endif


FG_NS_BEGIN

using namespace IO;

//--------------------------------------------------------------------------
//Path:
//
//--------------------------------------------------------------------------

#if FG_TARGET_PLATFORM == FG_TARGET_WIN
#	define TAG_PATH_DIR_SPLITE "//"
#else
#	define TAG_PATH_DIR_SPLITE "\\"
#endif
Path::Path():mPath()
fname()
,fext()
,pathSplit()
{

}

Path::Path(std::string path): mPath(path)
fname()
,fext()
,pathSplit()
{
	this->SetPath(path);
}

Path:: ~Path(void){

}

void Path::SetPath(std::string path){
	this->mPath = path ;
#if FG_TARGET_PLATFORM == FG_TARGET_WIN
	this->mPath = StringHelper::replace_all(this->mPath ,"//",TAG_PATH_DIR_SPLITE); 
#else
	this->mPath = StringHelper::replace_all(this->mPath ,"\\",TAG_PATH_DIR_SPLITE);
#endif

}

const char* Path::GetFullPathCstr() const{
	return this->mPath.c_str();	
}

std::string Path::GetFileName() const {
	if(this->fname.empty()) {
		if(this->pathSplit.size() == 0) {
			this->pathSplit = StringHelper::split(this->mPath,TAG_PATH_DIR_SPLITE);
		}
		std::vector<std::string> &split = this->pathSplit;
		if(split.size() > 0) {
			this->fname = split[split.size()-1];
		}
	}
	return this->fname;
}

std::string Path::GetFileExtention() const{
	if(this->fext.empty()){
		if(this->fname.size() == 0){
			this->fname = this->GetFileName();
			std::vector<std::string> split = StringHelper::split(this->fname,".");
			if(split.size() > 1){
				this->fext = split[split.size()-1];
			}
		}
	}
	return this->fext;
}

std::string Path::GetFileWithExtention() const{
	std::string tag(this->fname);
	tag.append(".");
	tag.append(this->fext);
	return tag;
}

std::string Path::GetParentDirectory() const{
	if(this->pathSplit.size() == 0){
		this->pathSplit = StringHelper::split(this->mPath,TAG_PATH_DIR_SPLITE);
	}
	std::string pat;
	for(int i=0;i< pathSplit - 1;i++){
		pat.append(pathSplit[i]);
		pat.append(TAG_PATH_DIR_SPLITE);
	}
	return pat;
}

FG_Boolean Path::IsDirectory() const{
	const char* pat = this->mPath.c_str();
#if FG_TARGET_PLATFORM == FG_TARGET_WIN
	char szFileName[MAX_PATH];  
    char szFilePath[MAX_PATH];  
    WIN32_FIND_DATA findFileData;  
    strcpy_s(szFilePath, lpPath);  
    strcat_s(szFilePath, "\\*.*");  
    HANDLE hFind = ::FindFirstFile(szFilePath, &findFileData);  
    if (INVALID_HANDLE_VALUE == hFind) return FG_False;
    else {
    	FG_Boolean ret = findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
    	FindClose(hFind);
    	return ret;
    }
#else
    struct stat s_buf;  
    stat(this->mPath.c_str(),&s_buf);  
    return S_ISDIR(s_buf.st_mode) == 1;
#endif
}

//static
FG_Boolean Path::IsDirectory(const char* path){
	Path _path(path);
	return _path.IsDirectory();
}

//--------------------------------------------------------------------------
//File:
//
//--------------------------------------------------------------------------

File::File(const char* path):mPath
,mpos(0)
,mCloseFlag(FG_False)
,mSize(FG_UNINIT_VAL)
{

}

File::~File(void){
	if(this->mCloseFlag == FG_False) {
		this->Close();
	}
}

FG_Boolean File::Eof();{
	return this->mpos >= this->GetLength();
}

FG_Cursor File::GetPos(){
	return this->mpos;
}

FG_Size File::GetLength(){
	if(this->mSize == FG_UNINIT_VAL) {
	    struct stat s_buf;  
		stat(this->mPath.c_str(),&s_buf);  
		this->mSize = s_buf.st_size;
	}
	return this->mSize;
}

void File::WriteAsy(const char* bytes,FG_Size size){
	FILE* f = fopen(this->mPath.GetFullPathCstr(),"rb");
	if(f && fwrite(bytes,f,size) == size) {
		fflush(f);
	}
	fclose(f);
}

void File::Write(const char* bytes,FG_Size size){
	FILE* f = fopen(this->mPath.GetFullPathCstr(),"rb");
	if(f && fwrite(bytes,f,size) == size) {
		fflush();
	}
	fclose(f);
	//check write file is complate.
	while (true) {
		if(this->GetLength() >= size) break;
        sleep(1); //sleep 1 second.
	}
}

void File::Write(const std::istream& stream){

}

std::ostream& File::GetStream(){

}

void File::Close(){
	this->mCloseFlag = FG_True;
}

void File::SetPos( FG_Cursor pos){

}

static FG_Boolean File::IsExist(const Path& path){

}

static File* File::Open(const Path& path){

}

static File* File::CreateFile(const Path& path,FG_Boolean _override){

}

//--------------------------------------------------------------------------
//File:
//
//--------------------------------------------------------------------------

std::vector<Path> Directory::getChildren(){

}

// static 
FG_Boolean Directory::CreateDir(const Path& path,FG_Boolean _override){

}

// static 
FG_Boolean Directory::CreateDir(const char* path,FG_Boolean _override){

}

// static 
FG_Boolean Directory::IsExist(const Path& path){

}

FG_NS_END

#endif