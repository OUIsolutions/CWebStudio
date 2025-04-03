## Search Requirements

Search Requirements are where you specify which elements the browser must return to the bridge lambda.

```c

CWebHyDrationBridge * alert_bridge = bridge_module.create_bridge(
    hydration,
    ALERT_BRIDGE,
    alert_bridge_callback
);

CWebHyDrationSearchRequirements *name =
requirements.newSearchRequirements(alert_bridge,"name");
requirements.add_elements_by_id(name,"name");

```

This example shows how to set up search requirements for a bridge.