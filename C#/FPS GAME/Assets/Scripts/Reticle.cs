using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Reticle : MonoBehaviour
{
    public LayerMask layerMask;
    public Image reticle;
    public float maxSize;
    public Camera MainCamera;
    public float maxDistance = 20f;

    public float range;
    // Start is called before the first frame update
    private void Start()
    {
        reticle.GetComponent<RectTransform>();
    }

    private void Update()
    {
        float distance = maxDistance;
        RaycastHit hit;
        Ray ray = Camera.main.ScreenPointToRay(new Vector3(0.5f, 0.5f));
        if (Physics.Raycast(ray, out hit, maxDistance, layerMask))
        {
            distance = hit.distance;
            Debug.Log(distance);
        }
    }
}
