#include "flowtranfer.hpp"
#include <thread>
#include <chrono>
#include <unistd.h>
#include <iostream>
#include <sys/time.h>

void buffertohandle(const char *buf,size_t buf_size,cudaIpcMemHandle_t *my_handle)
{
    memcpy((char *)(my_handle), buf, sizeof(*my_handle));
}

void recv(const char *topic,const char *data,size_t size)
{
    char buf[128];
    char *data1;
    cudaIpcMemHandle_t my_handle;

    buffertohandle(data,sizeof(cudaIpcMemHandle_t),&my_handle);
    cudaIpcOpenMemHandle((void **)&data1, my_handle, cudaIpcMemLazyEnablePeerAccess);
    cudaMemcpy(buf, data1, 64*sizeof(char), cudaMemcpyDeviceToHost);
    //std::cout << data << std::endl;
    printf("%s \n",buf);
}
int main(int argc ,char **argv)
{
	FlowRecv *ptr = new FlowRecv("0.0.0.0","24014","camera0",&recv);
	while(1){
        sleep(1);
	}
}

