#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <streambuf>  

//#include <GL/glew.h>; // 包含glew来获取所有的必须OpenGL头文件
typedef char GLchar;

class Shader
{
public:
    // 程序ID
    //GLuint Program;
    // 构造器读取并构建着色器
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    // 使用程序
    //void Use();
};

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
    // 1. 从文件路径中获取顶点/片段着色器
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // 保证ifstream对象可以抛出异常：
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try 
    {
        // 打开文件
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // 读取文件的缓冲内容到流中
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();       
        // 关闭文件
        vShaderFile.close();
        fShaderFile.close();
        // 转换流至GLchar数组
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();     
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const GLchar* vShaderCode = vertexCode.c_str();
    const GLchar* fShaderCode = fragmentCode.c_str();
	std::cout<< vShaderCode ;
	std::cout<< "\n====================================================\n";
	std::cout<< fShaderCode << std::endl;	
}

int main(int argc, const char* argv[])
{
	if( 3==argc )        //方法一
	{
		Shader(argv[1],argv[2]);		
	}
	else if( 2==argc )   //方法二
	{
		std::ifstream t(argv[1]);  
		std::string str;//( std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>() );
		str.assign( std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>() );
		std::cout<< str <<std::endl;
	}
	else                 //方法三
	{        
		std::ifstream t;  
		int length;  
		t.open("rdbuf_istreambuf_iterator.cpp");  // open input file  
		t.seekg(0, std::ios::end);    // go to the end  
		length = t.tellg();           // report location (this is the length)  
		t.seekg(0, std::ios::beg);    // go back to the beginning  
		char *buffer = new char[length];    // allocate memory for a buffer of appropriate dimension  
		t.read(buffer, length);       // read the whole file into the buffer  
		std::cout<<buffer<<std::endl;
		t.close();                    // close file handle  		
	}	
	return 0;
}