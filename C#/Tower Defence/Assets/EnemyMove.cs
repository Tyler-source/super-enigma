
using System;
using UnityEngine;

public class EnemyMove : MonoBehaviour
{
    public float speed = 10f;

    private Transform target;
    private int pointIndex = 0;

    private void Start()
    {
        target = Waypoints.Wpts[0];
    }
    private void Update()
    {
        Vector3 dir = target.position - transform.position;
        transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);

        if(Vector3.Distance(transform.position, target.position) <= 0.2f)
        {
            NextWaypoint();
        }
    }

    private void NextWaypoint()
    {
        if (pointIndex >= Waypoints.Wpts.Length - 1)
        {
            Destroy(gameObject);
            return;
        }
        pointIndex++;
        target = Waypoints.Wpts[pointIndex];
    }
}
