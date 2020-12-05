
using System.Collections;
using UnityEngine;
using UnityEngine.UI;

public class SpawnWave : MonoBehaviour
{
    public Transform enemyPrefab;
    public Transform spawnPoint;

    public float intermissionTimer = 5f;
    private float countdown = 2f;

    public Text WaveText;

    private int WaveNumber = 1;

    private void Update()
    {
        if(countdown <= 0f)
        {
            StartCoroutine(Spawn());
            countdown = intermissionTimer;
        }
        countdown -= Time.deltaTime;

        WaveText.text = Mathf.Round(countdown).ToString();

    }

    IEnumerator Spawn()
    {
        for (int i = 0; i < WaveNumber; i++)
        {
            SpawnEnemy();
            yield return new WaitForSeconds(0.2f);
        }
        WaveNumber++;
    }

    private void SpawnEnemy()
    {
        Instantiate(enemyPrefab, spawnPoint.position, spawnPoint.rotation);
    }
}
