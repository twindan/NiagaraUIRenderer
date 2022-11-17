// Copyright 2022 - Michal Smoleň

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "NiagaraWidgetProperties.h"

#include "NiagaraUIComponent.generated.h"

class SNiagaraUISystemWidget;

/**
 * 
 */
UCLASS()
class NIAGARAUIRENDERER_API UNiagaraUIComponent : public UNiagaraComponent
{
	GENERATED_BODY()

public:
#if ENGINE_MAJOR_VERSION == 4
	typedef FVector2D FVector2f;
#endif 
	
	void SetAutoActivateParticle(bool AutoActivate);
	
	void SetTransformationForUIRendering(FVector2D Location, FVector2f Scale, float Angle);

	void RenderUI(SNiagaraUISystemWidget* NiagaraWidget, float ScaleFactor, FVector2f ParentTopLeft, const FNiagaraWidgetProperties* WidgetProperties);

	void AddSpriteRendererData(SNiagaraUISystemWidget* NiagaraWidget, TSharedRef<const FNiagaraEmitterInstance, ESPMode::ThreadSafe> EmitterInst,
								class UNiagaraSpriteRendererProperties* SpriteRenderer, float ScaleFactor, FVector2f ParentTopLeft, const FNiagaraWidgetProperties* WidgetProperties);

	void AddRibbonRendererData(SNiagaraUISystemWidget* NiagaraWidget, TSharedRef<const FNiagaraEmitterInstance, ESPMode::ThreadSafe> EmitterInst,
                                class UNiagaraRibbonRendererProperties* RibbonRenderer, float ScaleFactor, FVector2f ParentTopLeft, const FNiagaraWidgetProperties* WidgetProperties);

protected:
#if ENGINE_MAJOR_VERSION == 4
	bool HasSystemInstanceInternal() const { return GetSystemInstance() != nullptr; }
	FNiagaraSystemInstance *GetSystemInstanceInternal() const { return GetSystemInstance(); }
#else
	bool HasSystemInstanceInternal() const { return GetSystemInstanceController() != nullptr; }
	FNiagaraSystemInstance *GetSystemInstanceInternal() const { return GetSystemInstanceController()->GetSystemInstance_Unsafe(); } 
#endif

private:
	bool AutoActivateParticle = false;

	friend class FNiagaraWidgetDetailCustomization;
};
