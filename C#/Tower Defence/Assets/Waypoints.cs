
using UnityEngine;

public class Waypoints : MonoBehaviour
{
    public static Transform[] Wpts;


    private void Awake()
    {
        Wpts = new Transform[transform.childCount];
        for (int i = 0; i < Wpts.Length; i++)
        {
            Wpts[i] = transform.GetChild(i);
        }
    }
}
