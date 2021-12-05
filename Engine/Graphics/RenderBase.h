#pragma once
#include <memory>
#include <string>

#include "Engine/Graphics/HWLContainer.h"
#include "Engine/Graphics/IRender.h"


class RenderBase : public IRender {
 public:
    inline RenderBase(
        std::shared_ptr<OSWindow> window,
        DecalBuilder* decal_builder,
        LightmapBuilder* lightmap_builder,
        SpellFxRenderer* spellfx,
        std::shared_ptr<ParticleEngine> particle_engine,
        std::shared_ptr<AssetsLocator> assets_locator,
        Vis* vis,
        Log* logger
    ) : IRender(window, decal_builder, lightmap_builder, spellfx, particle_engine, assets_locator, vis, logger) {
    }

    virtual bool Initialize();

    virtual void TransformBillboardsAndSetPalettesODM();
    virtual void DrawSpriteObjects_ODM();
    virtual void MakeParticleBillboardAndPush(SoftwareBillboard *a2,
                                                  Texture *texture,
                                                  unsigned int uDiffuse,
                                                  int angle);

    virtual HWLTexture *LoadHwlBitmap(const std::string &name);
    virtual HWLTexture *LoadHwlSprite(const std::string &name);

 protected:
    unsigned int Billboard_ProbablyAddToListAndSortByZOrder(float z);
    void TransformBillboard(SoftwareBillboard *a2, RenderBillboard *pBillboard);

    void PostInitialization();

    HWLContainer pD3DBitmaps;
    HWLContainer pD3DSprites;
};
