#ifndef FGCORE_IO_SYSTEM
#define FGCORE_IO_SYSTEM 1

#include <FGCore/Config.h>
#include <FGCore/Macros.h>
#include <FGCore/Types.h>
#include <FGCore/String.h>
#include <ostream>
#include <istream>


FG_NS_BEGIN

namespace IO {

	class Path {
		 public:

		 	Path();

		 	Path(std::string path);

		 	virtual ~Path(void);

		 	void SetPath(std::string path);

		 	const char* GetFullPathCstr() const;

		 	std::string GetFileName() const;

		 	std::string GetFileExtention() const;

		 	std::string GetFileWithExtention() const;

		 	std::string GetParentDirectory() const;

		 	FG_Boolean IsDirectory() const;

		 	static FG_Boolean IsDirectory(const char* path);

		 private:

		 	std::string mPath;
		 	mutable std::string fname;
		 	mutable std::string fext;
		 	mutable std::vector<std::string> pathSplit;
	};

	class File {

	private:

		Path mPath;

		FG_Cursor mpos;

		FG_Boolean mCloseFlag;

		FG_Size mSize;

	public:

		File(const char* path);

		virtual ~File(void);

		FG_Boolean Eof();

		FG_Cursor GetPos();

		FG_Size GetLength();

		void WriteAsy(const char* bytes,FG_Size size);

		void Write(const char* bytes,FG_Size size);

		void Write(const std::istream& stream);

		template<typename T>
		inline std::ostream& operator <<(T *t){
			std::ostream _ostream(nullptr);
			_ostream << *t;
			return _ostream;
		} ;

		template<typename T>
		inline std::istream& operator>>(T* t){
			// std::ostream ;
		};

		std::ostream& GetStream();

		void Close();

		void SetPos( FG_Cursor pos);

		static FG_Boolean IsExist(const Path& path);

		static File* Open(const Path& path);

		static File* CreateFile(const Path& path,FG_Boolean _override = false);
	};


	class Directory {

	public:

		std::vector<Path> getChildren();

		static FG_Boolean CreateDir(const Path& path,FG_Boolean _override);

		static FG_Boolean CreateDir(const char* path,FG_Boolean _override);

		static FG_Boolean IsExist(const Path& path);
	};

};

FG_NS_END

#endif