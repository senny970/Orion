#pragma once

namespace U
{
  class VMTHook
  {
  public:

    enum Tables
    {
      D3D_QueryInterface,
      D3D_AddRef,
      D3D_Release,
      D3D_TestCooperativeLevel,
      D3D_GetAvailableTextureMem,
      D3D_EvictManagedResources,
      D3D_GetDirect3D,
      D3D_GetDeviceCaps,
      D3D_GetDisplayMode,
      D3D_GetCreationParameters,
      D3D_SetCursorProperties,
      D3D_SetCursorPosition,
      D3D_ShowCursor,
      D3D_CreateAdditionalSwapChain,
      D3D_GetSwapChain,
      D3D_GetNumberOfSwapChains,
      D3D_Reset,
      D3D_Present,
      D3D_GetBackBuffer,
      D3D_GetRasterStatus,
      D3D_SetDialogBoxMode,
      D3D_SetGammaRamp,
      D3D_GetGammaRamp,
      D3D_CreateTexture,
      D3D_CreateVolumeTexture,
      D3D_CreateCubeTexture,
      D3D_CreateVertexBuffer,
      D3D_CreateIndexBuffer,
      D3D_CreateRenderTarget,
      D3D_CreateDepthStencilSurface,
      D3D_UpdateSurface,
      D3D_UpdateTexture,
      D3D_GetRenderTargetData,
      D3D_GetFrontBufferData,
      D3D_StretchRect,
      D3D_ColorFill,
      D3D_CreateOffscreenPlainSurface,
      D3D_SetRenderTarget,
      D3D_GetRenderTarget,
      D3D_SetDepthStencilSurface,
      D3D_GetDepthStencilSurface,
      D3D_BeginScene,
      D3D_EndScene,
      D3D_Clear,
      D3D_SetTransform,
      D3D_GetTransform,
      D3D_MultiplyTransform,
      D3D_SetViewport,
      D3D_GetViewport,
      D3D_SetMaterial,
      D3D_GetMaterial,
      D3D_SetLight,
      D3D_GetLight,
      D3D_LightEnable,
      D3D_GetLightEnable,
      D3D_SetClipPlane,
      D3D_GetClipPlane,
      D3D_SetRenderState,
      D3D_GetRenderState,
      D3D_CreateStateBlock,
      D3D_BeginStateBlock,
      D3D_EndStateBlock,
      D3D_SetClipStatus,
      D3D_GetClipStatus,
      D3D_GetTexture,
      D3D_SetTexture,
      D3D_GetTextureStageState,
      D3D_SetTextureStageState,
      D3D_GetSamplerState,
      D3D_SetSamplerState,
      D3D_ValidateDevice,
      D3D_SetPaletteEntries,
      D3D_GetPaletteEntries,
      D3D_SetCurrentTexturePalette,
      D3D_GetCurrentTexturePalette,
      D3D_SetScissorRect,
      D3D_GetScissorRect,
      D3D_SetSoftwareVertexProcessing,
      D3D_GetSoftwareVertexProcessing,
      D3D_SetNPatchMode,
      D3D_GetNPatchMode,
      D3D_DrawPrimitive,
      D3D_DrawIndexedPrimitive,
      D3D_DrawPrimitiveUP,
      D3D_DrawIndexedPrimitiveUP,
      D3D_ProcessVertices,
      D3D_CreateVertexDeclaration,
      D3D_SetVertexDeclaration,
      D3D_GetVertexDeclaration,
      D3D_SetFVF,
      D3D_GetFVF,
      D3D_CreateVertexShader,
      D3D_SetVertexShader,
      D3D_GetVertexShader,
      D3D_SetVertexShaderConstantF,
      D3D_GetVertexShaderConstantF,
      D3D_SetVertexShaderConstantI,
      D3D_GetVertexShaderConstantI,
      D3D_SetVertexShaderConstantB,
      D3D_GetVertexShaderConstantB,
      D3D_SetStreamSource,
      D3D_GetStreamSource,
      D3D_SetStreamSourceFreq,
      D3D_GetStreamSourceFreq,
      D3D_SetIndices,
      D3D_GetIndices,
      D3D_CreatePixelShader,
      D3D_SetPixelShader,
      D3D_GetPixelShader,
      D3D_SetPixelShaderConstantF,
      D3D_GetPixelShaderConstantF,
      D3D_SetPixelShaderConstantI,
      D3D_GetPixelShaderConstantI,
      D3D_SetPixelShaderConstantB,
      D3D_GetPixelShaderConstantB,
      D3D_DrawRectPatch,
      D3D_DrawTriPatch,
      D3D_DeletePatch,
      D3D_CreateQuery
    };

    VMTHook(
      const std::string &sHookName,
      void* pVMTObject,
      int iFnIndex,
      void* pHkFunction);

    ~VMTHook();

    std::string GetName() const;

    void* GetVMTObject() const;
    template<class T> T GetVMTObject() const
    {
      return (T)GetVMTObject();
    }

    void* GetOriginFn() const;
    template<class T> T GetOriginFn() const
    {
      return (T)GetOriginFn();
    }

    void* GetHookFn() const;
    template<class T> T GetHookFn() const
    {
      return (T)GetHookFn();
    }


    int GetFnIndex() const;

    bool SetName(const std::string &sNewName);
    bool SetVMTObject(void* pNewVMTObject);
    bool SetOriginFn(void* pNewOriginFn);
    bool SetHookFn(void* pNewHookFn);
    bool SetFnIndex(int iNewFnIndex);

    bool Apply();
    bool Restore();

  private:
    std::string m_sHookName;

    void* m_pVMTObject;
    void* m_pOriginFn;
    void* m_pHookFn;

    int m_iFnIndex;

    bool m_bHooked;
  };
}