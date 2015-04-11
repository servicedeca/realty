<div class="container fin last-block">
  <div class="col-xs-12 table-block text-center zero-padding">
    <br><br><br>
    <table class="table issue-table display" id="office">
      <thead>
        <tr>
        <tr>
          <th>
            ID квартиры
          </th>
          <th>
            Бронирование
          </th>
          <th class="width-200">
            Подтвержденные сделки
          </th>
          <th>
            Сертификат
          </th>
        </tr>
      </thead>
      <tbody>
        <?php if (!empty($apartments)): ?>
          <?php foreach ($apartments as $apartment):?>
            <tr>
              <td>
                <?php print $apartment['id']?>
              </td>
              <td>
                <?php print $apartment['book']?>
              </td>
              <td>
                <input class="form-control office-input" placeholder="Введите № договора">
                <input class="form-control office-input" placeholder="Введите ФИО по договору">
              </td>
              <td>
                <a href="#"> запросить<br> сертификат</a>
              </td>
            </tr>
        <?php endforeach; ?>
      <?php endif; ?>
      </tbody>
    </table>
  </div>
</div>