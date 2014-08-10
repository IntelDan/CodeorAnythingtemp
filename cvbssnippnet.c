#define INCLUDE_MUX_LINK_INSTEAD_OF_MERGE ???
//for dup link
dupId[SCALER_DUP_IDX] = SYSTEM_VPSS_LINK_ID_DUP_2;
cameraPrm.outQueParams[1].nextLink = dupId[SCALER_DUP_IDX];
ispPrm.outQueInfo[1].nextLink    = dupId[SCALER_DUP_IDX];
dupPrm[SCALER_DUP_IDX].inQueParams.prevLinkId = gVcamModuleContext.cameraId;
dupPrm[SCALER_DUP_IDX].inQueParams.prevLinkQueId = 1;
dupPrm[SCALER_DUP_IDX].numOutQue = 3;

#ifdef INCLUDE_MUX_LINK_INSTEAD_OF_MERGE                                                     
dupPrm[SCALER_DUP_IDX].outQueParams[0].nextLink = gVsysModuleContext.muxId;              
#else                                                                                        
dupPrm[SCALER_DUP_IDX].outQueParams[0].nextLink =                                        
  mergeId[CAM_STREAM_MERGE_IDX];

dupPrm[SCALER_DUP_IDX].outQueParams[1].nextLink = gVcamModuleContext.sclrId[0];
dupPrm[SCALER_DUP_IDX].outQueParams[2].nextLink =
  gVdisModuleContext.displayId[VDIS_DEV_SD];
dupPrm[SCALER_DUP_IDX].notifyNextLink = TRUE;

/* display link params */
MULTICH_INIT_STRUCT(DisplayLink_CreateParams,displayPrm_SD);
displayPrm_SD.inQueParams[0].prevLinkId = dupId[SCALER_DUP_IDX];
displayPrm_SD.inQueParams[0].prevLinkQueId = 2;
displayPrm_SD.displayRes = gVdisModuleContext.vdisConfig.deviceParams[VDIS_DEV_SD].resolution;
displayPrm_SD.displayId  = DISPLAY_LINK_DISPLAY_SD;       

/* Links Creation */
/* Camera Link */
System_linkCreate(gVcamModuleContext.cameraId, &cameraPrm,
		  sizeof(cameraPrm));

    /* Links Creation */
    /* Camera Link */
    System_linkCreate(gVcamModuleContext.cameraId, &cameraPrm,
                      sizeof(cameraPrm));
   System_linkControl(gVcamModuleContext.cameraId,
                       CAMERA_LINK_CMD_DETECT_VIDEO, NULL, 0, TRUE);
		   /* Dup link for display */
		   System_linkCreate(dupId[DIS_DUP_IDX], &dupPrm[DIS_DUP_IDX],
				     sizeof(dupPrm[DIS_DUP_IDX]));         
/* Dup Link for Scaler */
System_linkCreate(dupId[SCALER_DUP_IDX], &dupPrm[SCALER_DUP_IDX],
		  sizeof(dupPrm[SCALER_DUP_IDX]));

/* display link */
System_linkCreate(gVdisModuleContext.displayId[VDIS_DEV_SD], &displayPrm_SD,
		  sizeof(displayPrm_SD)); 

//folder:./ipnc_mcfw/mcfw/src_linux/mcfw_api/ti_vsys.c
Int32 Vsys_create()
{
  MultiCh_createTriStreamFullFt;
}


//还少个System_linkControl


//除了创建还有delete,fuck


//这是已经有的定义,放在这里是提示自己这个函数的实现
static inline Void DisplayLink_CreateParams_Init(DisplayLink_CreateParams *prm)
{
  memset(prm, 0, sizeof(*prm));

  prm->numInputQueues = 1;
  prm->activeQueue    = 0;
  prm->forceFieldSeparatedInputMode = FALSE;

  memset(prm->inQueParams,0,sizeof(prm->inQueParams));
  prm->displayId = DISPLAY_LINK_DISPLAY_AUTO_SELECT;
}

//注意这里:这段代码也是将dupId[SCALER_DUP_IDX]设置为prevLinkId,但是
//这里是muxPrm.inQueParams[1]的,和本snippet中的displayPrm_SD.inQueParams[0].prevLinkId
//没有关系--这就要求看懂Mcfw guide中关于Module Link中一个Link可以有0-N个
//inQue和outQue有关系了,不要搞混
muxPrm.inQueParams[1].prevLinkId = dupId[SCALER_DUP_IDX];
muxPrm.inQueParams[1].prevLinkQueId = 0;

//再放一个例子:
//这里要说的就是每一个Link在自己的结构体中有各自关于System_LinkInQueParams的定义
//比如下面的代码就是sclrPrm关于自己的System_LinkInQueParams的定义
//可以看到这只是一维结构体,而有的则是一个结构体的数组,比如上面代码中displayPrm_SD
//该link create parmas的定义就是一个数组
//    System_LinkInQueParams   inQueParams[DISPLAY_LINK_MAX_NUM_INPUT_QUEUES];


/**< Display link input information */  
/**< System configuration ID. */
//System_LinkInQueParams      inQueParams;
///**< Input queue information. */
//System_LinkOutQueParams     outQueParams;
/**< Output queue information. */

/* Scaler Link Params */
SclrLink_CreateParams_Init(&sclrPrm);
sclrPrm.inQueParams.prevLinkId             = dupId[SCALER_DUP_IDX];
sclrPrm.inQueParams.prevLinkQueId          = 1;


//linkcreate params的定义
CameraLink_CreateParams cameraPrm;
IspLink_CreateParams  ispPrm;
GlbceLink_CreateParams  glbcePrm;
UInt32 glbceId;
NsfLink_CreateParams nsfPrm;
VnfLink_CreateParams vnfPrm;
#ifdef INCLUDE_MUX_LINK_INSTEAD_OF_MERGE
MuxLink_CreateParams muxPrm;
#else
MergeLink_CreateParams mergePrm[NUM_MERGE_LINK];
#endif
IpcLink_CreateParams ipcOutVpssPrm;
IpcLink_CreateParams ipcInVideoPrm;
EncLink_CreateParams encPrm;
DupLink_CreateParams dupPrm[NUM_DUP_LINK];
SclrLink_CreateParams       sclrPrm;
DisplayLink_CreateParams displayPrm;
DisplayLink_CreateParams displayPrm_SD;
FdLink_CreateParams fdPrm;
SwosdLink_CreateParams swosdPrm;
IpcBitsOutLinkRTOS_CreateParams ipcBitsOutVideoPrm;
IpcBitsInLinkHLOS_CreateParams ipcBitsInHostPrm0;
VstabLink_CreateParams vstabPrm;
GlbceSupportLink_CreateParams glbceSupportPrm;
VaLink_CreateParams vaPrm;
IpcFramesOutLinkRTOS_CreateParams ipcFramesOutVpssPrm;
IpcFramesInLinkRTOS_CreateParams ipcFramesInDspPrm;
MuxLink_CreateParams muxPrmVnf;

CameraLink_VipInstParams *pCameraInstPrm;
CameraLink_OutParams *pCameraOutPrm;
                                              
